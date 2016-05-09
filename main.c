
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

#define BUFFER_SIZE
<<<<<<< Updated upstream

int main ()
=======
int count, delete = 0, begin, end;

/*
 * Main for producer consumer
 * 1. Get command line arguments
 * 2. Initialize buffer
 * 3. Create producer thread(s)
 * 4. Create consumer thread(s)
 * 5. Sleep
 * 6. Exit
 */
int main (int arc, char *argv[])
>>>>>>> Stashed changes
{

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

	conThreadNum = atoi(arv[3]); // Get number of consumer threads
	if(conThreadNum < 1){
		printf("err5: invalid number of consumer threads. See user manual for run instructions."); // print out error
		return 0; // end
	}

}

<<<<<<< Updated upstream

=======
	// 2.
	sem_init(&full, 0, 0); // full semaphore no space available
	sem_init(&empty, 0, BUFFER_SIZE); // empty semaphore full vacancy
	pthread_mutex_init(&mutex, NULL); // mutex lock initialize

	// 3.
	 pthread_t producer[prodThreadNum]; // create pthread array producer for producer
	 char *prod = "Producer" //
	 int i = 0;
	 for(i, i < prodThreadNum, i++){ // for i < number of producer threads
		 pthread_create(*producer[i], NULL, producer, prod); // create a producer thread
	 }


	 // 4.
	  pthread_t consumer[conThreadNum]; // create pthread arrar consumer for consumer
	 char *con = "Consumer";
	 for(i=0; i < conThreadNum, i++){ // for i < number of consumer threads
		 pthread_create(*consumer[i], NULL, consumer, con); // create a consumer thread
	 }

	 // 5.
	 sleep(sleepTime); // sleep for sleepTime

	 return 0; // fin.
	 }

/*
 *  insert function takes in buffer_item item and attempts to insert it into the buffer
 * returns 0 if successful
 * returns -1 if failure
 */
int insert(buffer_item item){
	if(count != BUFFER_SIZE){ // if buffer is not at capacity
		buffer[end] = item; // item goes to the end of the buffer
		printf("Produced: %d", item); // print produced item
		end = (end + 1) % BUFFER_SIZE; // new end we use modulus because the buffer is circular
		count++; // increase counter
		return 0; // return 0 if successful
	}
	return -1; // return 1 if failure
	}
}
int delete_item()
{
  buffer_item item;

  while (count == 0)
  {
    //do nothing
  }
  item = buffer [delete];
  printf("Consumed:  %d ", buffer[delete])
  delete = (delete + 1 ) % BUFFER_SIZE;

  count --;
  return 0;
}
>>>>>>> Stashed changes
