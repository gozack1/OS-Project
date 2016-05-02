/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem

*/

#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#include <buffer.h>

sem_t full;
sem_t empty;

pthread_mutex_t mutex;

BUFFER_item buffer[BUFFER_SIZE];
