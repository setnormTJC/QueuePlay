#pragma once
#include <string>


namespace MySpace
{
	class QueueADT
	{
	protected:
		virtual void enqueue(const std::string& thingToEnqueue) = 0;
		/*THAT'S what I like about Texas!*/
		virtual void dequeue() = 0;
	};

	/*implemented using a C-style array (as opposed to a linked list (node) - based implementation*/
	class MyQueue : public QueueADT
	{
	private:
		static const int MAX_QUEUE_CAPACITY = 5;

		std::string theQueueData[MAX_QUEUE_CAPACITY];

		//int indexOfFIRSTElement; //... not always 0! -> play around with "circular arrays" (involving the mod operator) if desired 
		int indexOfLastElement = -1; //empty initially, with default constructor

	public:
		/*pushes element in at the end of the queue*/
		void enqueue(const std::string& thingToEnqueue);
		/*Removes element at the front of the queue*/
		virtual void dequeue();

		MyQueue();

	};
}


