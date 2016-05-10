/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem

*/

#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t full, empty; 
pthread_mutex_t mutex;

typedef int buffer_item; // define buffer_item
#define BUFFER_SIZE 5 // define buffer size
