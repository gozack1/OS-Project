
/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem
main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>

#include "buffer.h"

void *producer(void *param); // predefine producer
void *consumer(void *param); // predefine consumer

/*
Main for producer consumer
 1. Get command line arguments
 2. Initialize buffer
 3. Create producer thread(s)
 4. Create consumer thread(s)
 5. Sleep
 6. Exit
*/

int main (int argc, char* argv[]){

// 1.
 int sleepTime, prodThreadNum, conThreadNum;
	if(argc < 4){ // If there are too few arguments
		printf("err1: too few arguments.\nSee user manual for run instructions."); // print out error
		return 0; // end
	}

	if(argc > 4){ // If there are too many arguments
		printf("err2: too many arguments.\nSee user manual for run instructions."); // print out error
		return 0; // end
	}

	sleepTime = atoi(argv[1]); // Get sleep time
	if(sleepTime < 1){ // if sleep time is less than 1
		printf("err3: invalid sleep time. See user manual for run instructions."); // print out error
		return 0; // end
	}

	prodThreadNum = atoi(argv[2]); // Get number of producer threads
	if(prodThreadNum < 1){
		printf("err4: invalid number of producer threads. See user manual for run instructions."); // print out error
		return 0; // end
	}

	conThreadNum = atoi(argv[3]); // Get number of consumer threads
	if(conThreadNum < 1){
		printf("err5: invalid number of consumer threads. See user manual for run instructions."); // print out error
		return 0; // end
	}

	  srand(time(NULL)); // null

	srand(time(NULL)); // set null seed value


	// 2.
	sem_init(&full, 0, 0); // full semaphore no space available
	sem_init(&empty, 0, BUFFER_SIZE); // empty semaphore full vacancy
	pthread_mutex_init(&mutex, NULL); // mutex lock initialize

	// 3.
	 pthread_t produce[prodThreadNum]; // create pthread array producer for producer
	 char *prod = "Producer"; //
	 char *prod = "Producer"; // producer arg

	 int i;
	 for(i=0; i < prodThreadNum; i++){ // for i < number of producer threads
		 pthread_create(&produce[i], NULL, producer, prod);
	 }


	 // 4.
	  pthread_t consume[conThreadNum]; // create pthread arrar consumer for consumer
	 char *con = "Consumer";

	 char *con = "Consumer"; // consumer arg
	 for(i=0; i < conThreadNum; i++){ // for i < number of consumer threads
		 pthread_create(&consume[i], NULL, consumer, con); // create a consumer thread
	 }

	 // 5.
	 sleep(sleepTime); // sleep for sleepTime

	 return 0; // fin.
	 }
