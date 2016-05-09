/*
OS Project
Mikal Callahan and Zachary Go
Producer-Consumer Problem

*/

#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#include "buffer.h"

<<<<<<< Updated upstream:OS Project/buffer.c
buffer_item buffer[BUFFER_SIZE];
=======
BUFFER_item buffer[BUFFER_SIZE]; // define buffer size
>>>>>>> Stashed changes:buffer.c


/*
 *  insert function takes in buffer_item item and attempts to insert it into the buffer
 * returns 0 if successful
 * returns -1 if failure
 */
int insert(buffer_item item){
	if(count != BUFFER_SIZE){ // if buffer is not at capacity
		buffer[end] = item; // item goes to the end of the buffer
		printf("Produced: %d", item); // print produced item
		end = (end + 1) % BUFFER_SIZE; // new end we use modulus because the buffer is circular
		count++; // increase counter
		return 0; // return 0 if successful
	}
	return -1; // return 1 if failure
	}
}
int delete_item()
{
  buffer_item item;

  while (count == 0)
  {
    //do nothing
  }
  item = buffer [delete];
  printf("Consumed:  %d ", buffer[delete])
  delete = (delete + 1 ) % BUFFER_SIZE;

  count --;
  return 0;
}
