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

int count, del, begin, end;

buffer_item buffer[BUFFER_SIZE]; // define buffer size

/*
 *  insert function takes in buffer_item item and attempts to insert it into the buffer
 * returns 0 if successful
 * returns -1 if failure
 */
int insert(buffer_item item)
{
	if(count != BUFFER_SIZE){ // if buffer is not at capacity
		buffer[end] = item; // item goes to the end of the buffer
		printf("Produced: %d", item); // print produced item
		end = (end + 1) % BUFFER_SIZE; // new end we use modulus because the buffer is circular
		count++; // increase counter
		return 0; // return 0 if successful
	}
	return -1; // return 1 if failure
	}

int delete_item(buffer_item *item)
{
  while (count == 0)
  {
    //do nothing
  }
  item = &buffer[del];
  printf("Consumed:  %d ", buffer[del]);
  del = (del+ 1) % BUFFER_SIZE;

  count --;
  return 0;
}

void printOutBuffer()
{
	int x;
	printf("Buffer: [");
	if (count  == 0)
	{
		printf("Buffer Empty!");
	}
	else
	{
	if (end > del)
		{
			for(x = del; x < end; x++)
			{
				printf(" %x ", buffer[x]);
			}
		}
	if (end <= del)
	{
		for(x = del; x < BUFFER_SIZE; x++)
		{
			prinf(" %x ", buffer[x]);
		}
		for (x = 0; x < end; x++)
		{
			printf(" %x ", buffer[x]);
		}
	}

	}

	printf("]\n");
}
