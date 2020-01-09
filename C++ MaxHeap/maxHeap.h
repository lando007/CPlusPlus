/*
-HW:Project 7
-Name: Luke Landon
-Compiler Used:Visual Studio
-File type: cpp
*/
#ifndef HEAP_H
#define HEAP_H
class MaxHeap
{
	int* arr;		// pointer to array of elements in heap
	int capacity;	// maximum possible size of min heap
	int size;		// Current number of elements in min heap

	int parent(int i); //top current node
	int left(int i); //left node under current node
	int right(int i); //right node under current node
	bool isLeaf(int i); //check to see if value is a leaf
	void swap(int* x, int* y); //swaps values in heap
	void siftup(int i);//moves value up the Heap
	void siftdown(int i);//moves value down the Heap
public:
	class Overflow {}; //Exeption if you try to put to many elements into the array
	class Underflow {};//Exeption if you try to take to many elements out of the array
	MaxHeap(int capacity); //initializes a MaxHeap with capactity elements
	int getSize(); //checks size of array
	int getMax(); //take spot 0 in the array
	void insert(int k); //inserts value in the array
	int extractMax(); //extracts spot 0 in the array
	int removeAt(int i); //removes value at location
	void heapify(int* array, int len); //creates a heap using heapify
	
};
#endif