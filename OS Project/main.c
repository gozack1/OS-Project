
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

int count,delete = 0; 
int main ()
{
  
  
}

int delete_item()
{
  buffer_item item;
  
  while (count == 0)
  {
    pr//do nothing
  }
  item = buffer [delete];
  printf("Consumed  %d ", buffe[delete])
  delete = (delete + 1 ) % BUFFER_SIZE;
  
  count --;
  return 0;
}
