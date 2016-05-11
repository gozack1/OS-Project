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

int count, start, end; // initialize count, start, and end

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
		printf("Produced: %d ", item); // print produced item
		end = (end + 1) % BUFFER_SIZE; // new end we use modulus because the buffer is circular
		count++; // increase counter
		return 0; // return 0 if successful
	}
	return -1; // return 1 if failure
	}

	/*
	 *  delete function takes in buffer_item item and attempts to delete it from the buffer
	 * returns 0 if successful
	 * returns -1 if failure
	 */
int delete_item(buffer_item *item)
{
  if (count > 0)
  {
  item = &buffer[start];
  printf("Consumed:  %d ", buffer[start]);
  start = (start+ 1) % BUFFER_SIZE;
  count --;
  return 0;
  }
  return -1;
  if (count > 0) // if count > 0
  {
  item = &buffer[start]; // item gets buffer start
  printf("Consumed:  %d ", buffer[start]); // print "consumed" and item number
  start = (start+ 1) % BUFFER_SIZE; // new start
  count --; // decrease count
  return 0; // return 0
  }
  return -1; // return -1 if failure
}

/*
 *	function to print out the contents of the buffer
 */
void printOutBuffer()
{
	int x;
	printf("Buffer: ["); // print beging buffer edge
	if (count  == 0) // buffer is empty
	{
		printf("Buffer Empty!"); // print empty
	}
	else
	{
	if (end > start)
		{
			x = start;
			for(x = start; x < end; x++)
	if (end > start) // if end > start
		{
			x = start; // x = start
			for(x = start; x < end; x++) // for x < end
			{
				printf(" %x ", buffer[x]); // print out buffer
			}
		}
	if (end <= start)
	{
		for(x = start; x < BUFFER_SIZE; x++)
		{
			printf(" %x ", buffer[x]);
	if (end <= start) // if end <= start
	{
		for(x = start; x < BUFFER_SIZE; x++) // for x < BUFFER_SIZE
		{
			printf(" %x ", buffer[x]); // print buffer
		}
		for (x = 0; x < end; x++) // for x < end
		{
			printf(" %x ", buffer[x]); // print buffer
		}
	}
	}

	printf("]\n");
	}
	printf("]\n"); // print end buffer bracket
}
