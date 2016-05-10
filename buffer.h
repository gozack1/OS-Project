/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem

*/

#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

<<<<<<< Updated upstream
sem_t full, empty; 
pthread_mutex_t mutex;
=======
sem_t full, empty; // delcare full, empty semaphores
pthread_mutex_t mutex; // declare mutex
>>>>>>> Stashed changes

typedef int buffer_item; // define buffer_item
#define BUFFER_SIZE 5 // define buffer size
