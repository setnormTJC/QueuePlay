#include "MyQueue.h"
#include <iostream>

#pragma region NaiveStaticQueue

void MySpace::NaiveStaticQueue::enqueue(const std::string& thingToEnqueue)
{
	if (indexOfLastElement > MAX_QUEUE_CAPACITY - 1)
	{
		throw std::exception("queue is full - cannot add more");
	}

	indexOfLastElement++;
	theQueueData[indexOfLastElement] = thingToEnqueue; 
}

/*In the worst case, N "customers" in line have to take a step "forward:"!
* That is, this implementation of dequeue has complexity O(N)
*/
void MySpace::NaiveStaticQueue::dequeue()
{
	if (indexOfLastElement == -1)
	{
		throw std::exception("queue is empty - cannot remove from empty queue");
	}

	std::cout << "Dequeueing " << theQueueData[0] << "\n";

	//O(N) complexity! (bad)
	//move previous second element to the first position, third to second, etc.: 
	for (int i = 1; i <= indexOfLastElement; ++i) 
	{
		std::cout << theQueueData[i] << " \"steps forward\"\n"; //optional print for visualization of queue mvmt
		theQueueData[i - 1] = theQueueData[i]; 
	}

	//(OPTIONAL) set the unoccupied positions to the empty string: 
	for (int i = indexOfLastElement; i < MAX_QUEUE_CAPACITY; ++i)
	{
		theQueueData[i] = "";
	}

	indexOfLastElement--; 
}


MySpace::NaiveStaticQueue::NaiveStaticQueue()
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

#pragma endregion

void MySpace::CircularStaticQueue::enqueue(const std::string& thingToEnqueue)
{
	if (isFull()) throw std::exception("queue is full - cannot add more");

	else if (isEmpty()) 
	{
		//set both first and last to 0 (the first index in an array)
		first = 0; 
		last = 0; 
		//(equivalently: first++; last++)
	}

	else
	{
		//last++;  //this is ONE way to do it

		last = (last + 1) % MAX_QUEUE_CAPACITY; //ANOTHER way (getting "circular")
		//ex: if last == -1 (initially empty), this becomes last = (-1 + 1) % 5 = 0
		//and if last == 0 (before calling this function), this becomes (0 + 1) % 5 = 1
		//...
		//and if last == 4, this becomes (4 + 1) % 5 = 0

		//Now this last example MIGHT seem like it overwrites the FIRST value in the queue
		//BUT look into the definition of `isFull` for that:
		//(returns true if (last + 1) % MAX_QUEUE_CAPACITY == first; -> (4 + 1) % 5 = 0 == 0

	}

	//now put the thing in: 
	theQueueData[last] = thingToEnqueue;
}

MySpace::CircularStaticQueue& MySpace::CircularStaticQueue::enqueueWithChaining(const std::string& thingToEnqueue)
{
	if (isFull()) throw std::exception("queue is full - cannot add more");

	else if (isEmpty())
	{
		//set both first and last to 0 (the first index in an array)
		first = 0;
		last = 0;
		//(equivalently: first++; last++)
	}

	else
	{
		last = (last + 1) % MAX_QUEUE_CAPACITY; //ANOTHER way (getting "circular")
	}

	theQueueData[last] = thingToEnqueue;
	
	return *this; 
}

void MySpace::CircularStaticQueue::dequeue()
{
	if (isEmpty()) throw std::exception("Queue is empty");

	//std::cout << "Dequeueing " << theQueueData[first] << "\n";

	if (first == last) //this means queue will be emptied as a result of this dequeue! "Flip reset"
	{
		first = -1;
		last = -1;
	}

	//first++; //not the best approach...
	else
	{
		first = (first + 1) % MAX_QUEUE_CAPACITY;
	}
}

bool MySpace::CircularStaticQueue::isEmpty() const
{
	if (first == -1)  
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool MySpace::CircularStaticQueue::isFull()
{
	//return (last == MAX_QUEUE_CAPACITY - 1); //one, "non-circular" way to do it: 
	
	int remainder = (last + 1) % MAX_QUEUE_CAPACITY; //making this a variable for ease of viewing in debugger...

	return remainder == first; 
}

std::string MySpace::CircularStaticQueue::front() const
{
	return theQueueData[first];
}


MySpace::CircularStaticQueue::CircularStaticQueue()
{
	for (int i = 0; i < MAX_QUEUE_CAPACITY; ++i)
	{
		theQueueData[i] = ""; //again, explicitly initializing to empty strings for "clarity"
	}
}

MySpace::CircularStaticQueue& MySpace::CircularStaticQueue::inPlaceMerge(CircularStaticQueue& other)
{
	while (other.isEmpty() == false)
	{
		if (!this->isEmpty())
		{
			this->enqueue(this->front());
			this->dequeue();
		}

		if (!other.isEmpty())
		{
			this->enqueue(other.front());
			other.dequeue();
		}
	}

	return *this; 
}

MySpace::CircularStaticQueue MySpace::CircularStaticQueue::outOfPlaceMerge(CircularStaticQueue& other)
{
	CircularStaticQueue newQueue; 

	bool isThisQueueEmpty = this->isEmpty(); 
	bool isOtherQueueEmpty = other.isEmpty(); 

	while (isThisQueueEmpty == false || isOtherQueueEmpty == false)
	{
		if (isThisQueueEmpty == false)
		{
			newQueue.enqueue(this->front()); 
			this->dequeue(); 
			isThisQueueEmpty = this->isEmpty(); 
		}

		if (isOtherQueueEmpty == false)
		{
			newQueue.enqueue(other.front());
			other.dequeue(); 
			isOtherQueueEmpty = other.isEmpty(); //check if other queue becomes empty after dequeueing
		}
	}

	return newQueue;
}

#pragma region ResizableQueue

MySpace::ResizeableQueue::ResizeableQueue()
{
}

void MySpace::ResizeableQueue::enqueue(const std::string& thingToEnqueue)
{
}

void MySpace::ResizeableQueue::dequeue()
{
}

bool MySpace::ResizeableQueue::isEmpty() const
{
	return theQueueData.size() == 0; 
}

void MySpace::ResizeableQueue::inPlaceMerge(const ResizeableQueue& otherQueue)
{

}

MySpace::ResizeableQueue MySpace::ResizeableQueue::outOfPlaceMerge(const ResizeableQueue& otherQueue)
{
	ResizeableQueue theNewQueue; //this will be a THIRD queue (created from merging "this" queue and otherQueue)
	
	/*Now what is the COMPLEXITY of this loop? ... O (m + n)? 
	* ...Where 'm' and 'n' are the sizes of "this" queue and other queue, respectively.
	*/
	while (this->isEmpty() == false || otherQueue.isEmpty() == false)
	{
		//get first from "this" queue and push into theNewQueue: 
		std::string frontElementInThisQueue = this->theQueueData.front(); //add safety check for nonempty queue
		theNewQueue.theQueueData.push_back(frontElementInThisQueue); 

		//same for the otherQueue:
		std::string frontElementInOtherQueue = this->theQueueData.front();
		theNewQueue.theQueueData.push_back(frontElementInOtherQueue);
	}

	return ResizeableQueue();
}

void MySpace::ResizeableQueue::appendOtherQueue(const ResizeableQueue& otherQueue)
{
}

#pragma endregion