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
#include <sys/types.h>

#include "buffer.h"

sem_t full, empty;

pthread_mutex_t mutex;

int delete_item(buffer_item *item);

void *consumer(void *param)
{
  buffer_item item;

  while (1)
  {
      sleep (rand () %10 + 1);

      sem_wait(&full);
      pthread_mutex_lock(&mutex);

      (delete_item(&item) < 0);

      pthread_mutex_unlock(&mutex);
      sem_post(&empty);

  }

}
