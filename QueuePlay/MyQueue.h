#pragma once
#include <string>


namespace MySpace
{
	class QueueADT
	{
	protected:
		virtual void enqueue(const std::string& thingToEnqueue) = 0;
		virtual void dequeue() = 0;

	};

	/*implemented using a C-style array (as opposed to a linked list (node) - based implementation*/
	class NaiveQueue : public QueueADT
	{
	private:
		static const int MAX_QUEUE_CAPACITY = 5;

		std::string theQueueData[MAX_QUEUE_CAPACITY];

		int indexOfLastElement = -1; //empty initially, with default constructor

	public:
		/*pushes element in at the end of the queue*/
		void enqueue(const std::string& thingToEnqueue);

		/*This implementation has complexity O(N) -> [a bad thing - we can do better]*/
		void dequeue();


		NaiveQueue();
	};

	/*Uses a "circular" array - which requires additional SPACE complexity but has better TIME complexity for dequeuing
	* Note the tradeoff between time and space 
	*/
	class NotAsNaiveQueue : public QueueADT
	{
	private:
		static const int MAX_QUEUE_CAPACITY = 5;

		std::string theQueueData[MAX_QUEUE_CAPACITY];

		/*the index of the first element (AKA: "customer to be serviced") in the queue*/
		int first = -1; // initialize to -1 because default constructor will make empty strings in `theQueueData` array 
		int last = -1;

	public: 
		void enqueue(const std::string& thingToEnqueue);
		/*Aiming at average time complexity O(1) here...*/
		void dequeue();

		bool isEmpty(); 
		bool isFull();

		std::string front(); 

		NotAsNaiveQueue(); 
	};
}


