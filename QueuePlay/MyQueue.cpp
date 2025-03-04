#include "MyQueue.h"
#include <iostream>

void MySpace::MyQueue::enqueue(const std::string& thingToEnqueue)
{
	if (indexOfLastElement > MAX_QUEUE_CAPACITY - 1)
	{
		throw std::exception("queue is full - cannot add more");
	}

	indexOfLastElement++;
	theQueueData[indexOfLastElement] = thingToEnqueue; 
}

void MySpace::MyQueue::dequeue()
{
	if (indexOfLastElement == -1)
	{
		throw std::exception("queue is empty - cannot remove from empty queue");
	}

	std::cout << "Dequeueing " << theQueueData[0] << "\n";

	//O(N) complexity! (bad)
	//move previous second element to the first position, third to second, etc.: 
	for (int i = 1; i <= indexOfLastElement; ++i) 
	//+ 1 to overwrite the former last element with empty string (goes out of bounds if queue is FULL!)
	{
		theQueueData[i - 1] = theQueueData[i]; 
	}

	//set the last element to the empty string: 
	theQueueData[indexOfLastElement] = "";

	indexOfLastElement--; 
}

MySpace::MyQueue::MyQueue()
{
	//theQueueData[0] = "Make";
	//theQueueData[1] = "us";
	//theQueueData[2] = "whole";
	//theQueueData[3] = "again, ";
	//theQueueData[4] = "Isaac";

	for (int i = 0; i < MAX_QUEUE_CAPACITY; ++i)
	{
		theQueueData[i] = ""; //EXPLICITLY initializing all queue elements to empty string
	}
}
