/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem
Producer.c
*/

#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include "buffer.h"

int insert(buffer_item item); // predefine insert function
int delete_item(buffer_item *item); // predefine delete function
int printOutBuffer(); // predefine printOutBuffer function

sem_t full, empty; // initialize semaphore full and empty
pthread_mutex_t mutex; // initialize pthread mutex mutex

/*
 *	Producer function to produce an item and
 * send the item to insert to be stored in buffer
 */
void *producer(void *p){
	buffer_item item; // create buffer_item item

	while(1){
		sleep(rand() % 7 + 1); // sleep for a random number of time
		item = rand() % 55 + 1; // item gets random item number
		sem_wait(&empty); // wait until there is an available space
		pthread_mutex_lock(&mutex); // critical section lock

		if(insert(item) != -1) // if the item was inserted
			printOutBuffer(); // call function to print out buffer contents
		pthread_mutex_unlock(&mutex); // come out of critical section lock
		sem_post(&full); // the slot is now full
	}
}
