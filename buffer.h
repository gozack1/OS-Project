/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem

*/
sem_t full, empty; 
typedef int buffer_item; // define buffer_item
#define BUFFER_SIZE 5 // define buffer size
