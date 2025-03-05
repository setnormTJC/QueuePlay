// QueuePlay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"MyQueue.h"

#include<array>
#include <iostream>

/*Using a copy so that original is not modified*/
void printQueue(MySpace::NotAsNaiveQueue notAsNaiveQueue)
{
	std::cout << "Queue contents (left is front, right is back)\n";
	while (!notAsNaiveQueue.isEmpty())
	{
		std::cout << notAsNaiveQueue.front() << " "; 
		notAsNaiveQueue.dequeue(); 
	}

}

void demoNaiveQueue()
{
	MySpace::NaiveQueue mq;

	try
	{
		mq.enqueue("Alice");
		mq.enqueue("Bob Loblaw");
		mq.enqueue("Carol");
		mq.enqueue("Darth");
		mq.enqueue("Eve");

		

		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue(); //throws
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
}


void demoNotAsNaiveQueue()
{
	MySpace::NotAsNaiveQueue notAsNaiveQueue;
	
	try
	{
		notAsNaiveQueue.enqueue("Alice");
		notAsNaiveQueue.enqueue("Bob Loblaw");
		notAsNaiveQueue.enqueue("Carol");
		notAsNaiveQueue.enqueue("Darth");
		notAsNaiveQueue.enqueue("Eve");

		std::cout << "After pushing A,B,C,D,E:\n";
		printQueue(notAsNaiveQueue);

		notAsNaiveQueue.dequeue(); //removes Alice
		notAsNaiveQueue.dequeue(); //ditto Bob
		notAsNaiveQueue.dequeue(); //"" Carol
		notAsNaiveQueue.dequeue(); //"" Darth

		notAsNaiveQueue.enqueue("Frank");

		notAsNaiveQueue.dequeue(); //removes Eve
		notAsNaiveQueue.dequeue(); //"" Frank

		notAsNaiveQueue.dequeue(); //throws exception
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

}

int main()
{
	//std::array<std::string, 4> ar;

	//demoNaiveQueue(); 
}
