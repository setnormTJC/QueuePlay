// QueuePlay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"MyQueue.h"

#include <iostream>

int main()
{
	MySpace::MyQueue mq;

	try
	{
		mq.enqueue("Alice");
		mq.enqueue("Bob Loblaw");
		mq.enqueue("Carol");
		mq.enqueue("Darth");
		mq.enqueue("Eve"); //throws "vector too long", at the moment - due to bug in dequeue


		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue();
		mq.dequeue();//throws
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

}
