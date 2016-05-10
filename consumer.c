/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem
consumer.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include "buffer.h"


<<<<<<< Updated upstream
int delete_item(buffer_item *item);
void printOutBuffer();

void *consumer(void *p)
{

  buffer_item item;

  while (1)
  {
      sleep (rand () % 7 + 1);

      sem_wait(&full);
      pthread_mutex_lock(&mutex);

      if (delete_item(&item)){

		}
=======
int delete_item(buffer_item *item); // predefine delete function
void printOutBuffer(); // predefine print function

/*
 * 	Consumer function takes in void p param
 *		sleeps for a random time, then deletes an item and prints out the buffer
 *
 */
void *consumer(void *p)
{
  buffer_item item; // declare buffer item item
  while (1)
  {
      sleep (rand () % 7 + 1); // sleep for random time
      sem_wait(&full); // wait
      pthread_mutex_lock(&mutex); // access critical section
      if (delete_item(&item) > 0){ // if item was not deleted
		} // do nothing
>>>>>>> Stashed changes
      else
      {
        printOutBuffer(); // else print buffer
      }
      pthread_mutex_unlock(&mutex); // release critical section
      sem_post(&empty); // another slot is now free
  }
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
}
