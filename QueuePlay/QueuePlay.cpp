// QueuePlay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"MyQueue.h"

#include<array>
#include <iostream>

/*Using a copy so that original is not modified*/
void printQueue(MySpace::CircularStaticQueue notAsNaiveQueue)
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
	MySpace::NaiveStaticQueue mq;

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
	MySpace::CircularStaticQueue notAsNaiveQueue;
	
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

void demoOutOfPlaceMerge()
{
	MySpace::CircularStaticQueue q1;
	q1.enqueue("Alice");
	q1.enqueue("Carol");

	MySpace::CircularStaticQueue q2;
	q2.enqueue("Bob");
	q2.enqueue("Darth");
	q2.enqueue("Eve");

	MySpace::CircularStaticQueue mergedQueue = q1.outOfPlaceMerge(q2);

	std::cout << "Contents of merged queue: \n";
	printQueue(mergedQueue);
}

/*"chaining" requires returning an object by reference and allows convenient syntax like:
object.functionName().functionName().functionName()*/
void demoChaining()
{
	MySpace::CircularStaticQueue q; 

	q.enqueueWithChaining("A").enqueueWithChaining("B").enqueueWithChaining("C");

	printQueue(q); 
}

void demoInPlaceMerge()
{
	MySpace::CircularStaticQueue q1;
	q1.enqueueWithChaining("A").enqueueWithChaining("C").enqueueWithChaining("E");

	MySpace::CircularStaticQueue q2;
	q2.enqueueWithChaining("B").enqueueWithChaining("D");

	q1.inPlaceMerge(q2).dequeue(); //note the chain!

	printQueue(q1);
}

int main()
{

}
