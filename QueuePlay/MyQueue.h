#pragma once
#include <string>
#include <vector>


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

	/*SHOULD a queue's max capacity be able to grow and shrink? 
	* Suppose your queue was previously serviced by a slow processor (cashier) - and now a faster one is used? 
	* Or the amount of available memory (RAM) on your machine increases
	*/
	class ResizeableQueue : public QueueADT
	{
	private: 
		std::vector<std::string> theQueueData; 
		int capacity = 5; //non-const!
	public: 
		ResizeableQueue(); 

		void enqueue(const std::string& thingToEnqueue);
		/*Aiming at average time complexity O(1) here...*/
		void dequeue();

		bool isEmpty() const; 

		/******************************************OPTIONAL member functions*******************/
		/*a resizeable queue might be a "natural" candidate for an inplace merge*/
		void inPlaceMerge(const ResizeableQueue& otherQueue); 
		
		/*return by reference?*/
		ResizeableQueue outOfPlaceMerge(const ResizeableQueue& otherQueue);

		void appendOtherQueue(const ResizeableQueue& otherQueue);
	};
}


