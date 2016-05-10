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
      else
      {
        printOutBuffer();
      }
      pthread_mutex_unlock(&mutex);
      sem_post(&empty);

  }

}
