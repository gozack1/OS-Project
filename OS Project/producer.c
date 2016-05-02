/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem
Producer.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include <buffer.h>


sem_t full, empty;

pthread_mutex_t mutex;

void *producer(void *param)
{
  
  
}
