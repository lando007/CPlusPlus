/*
-HW:Project 7
-Name: Luke Landon
-Compiler Used:Visual Studio
-File type: cpp
*/
#include <iostream>
#include "maxHeap.h"
using namespace std;
//Purpose: to create a MaxHeap array with size cap
//sets size to 0 
MaxHeap::MaxHeap(int cap)
{
	size = 0; capacity = cap;
	arr = new int[capacity];
}
//Purpose: return value of parent
int MaxHeap::parent(int i) {
	return (i - 1) / 2;
}
//Purpose: calculate return left node of parent
int MaxHeap::left(int i) {
	return (2 * i + 1);
}
//Purpose: calculate and return right node of parent
int MaxHeap::right(int i) {
	return (2 * i + 2);
}
//Purpose: return the current size of the array
int MaxHeap::getSize(){
	return size;
}
//Purpose: Checks to see if the node i is a leaf
bool MaxHeap::isLeaf(int i) {
	return (i < size / 2) ? false : true;
}
//Purpose: swap values of the node in the array
//passes in pointers to both locations and transfer content inside
void MaxHeap::swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
//Purpose: inserts the new node in the next available empty spot
//then continues swapping upword with its parent untill the new node is smaller then
//its parent or untill it reaches the root
void MaxHeap::siftup(int i) {
	//contues to swap untill i is greater the o and the parent is less then the current value

	while (i > 0 && arr[parent(i)] < arr[i])
	{
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}
}
//Purpose: Delete node number i and swap it with the last node. Then delete the last node
//put the out-of-place node downword continute swapping with its larger child until
//it is already larger then its children or until it is a leaf
void MaxHeap::siftdown(int i) {
	while (!isLeaf(i)) {
		int l = left(i);
		int r = right(i);
		int larger = arr[l];
		//checks to see if the right is less the the size 
		if (r < size)
			larger = (arr[l] > arr[r]) ? l : r;
		//checks to see if the current value is equal or larger then the array[larger]
		if (arr[i] >= arr[larger])
			break;
		//swaps i and larger
		swap(&arr[i], &arr[larger]);
		i = larger;
	}
}
//Purpose: to insert into the array
//1st checks to see if size is greater or equal to capacity if so throws overflow
//2nd runs sift up and increases the size by 1
void MaxHeap::insert(int k) {
	if (size >= capacity)
		throw Overflow();
	int i = size;
	arr[i] = k;
	siftup(i);
	size++;	
}
//Purpose: to delete the current node
//This is done 1. copu the last node to the current node, 2. delete the last node
//3. if the last node is smaller then the current node, then sift down the current
//node, 4. else if the last node is greater than the current node then lift down the 
//current node
int MaxHeap::removeAt(int i) {
	//checks to see if i is less then 0 or size is less the or equal to i if so thows underflow
	if (i < 0 || size <= i) throw Underflow();
	//checks to see if size is equal to one if so returns one less then sizxe
	if (size == 1) return arr[--size];
	int result = arr[i];
	arr[i] = arr[--size];
	//checks to see if current node is less then rusult if so sift down i
	if (arr[i] < result) siftdown(i);
	else siftup(i);
	return result;
}
//Purpose:  extract the root node 
//first checks to see if the size is less then or equal to zero this will throw underflow
//second checks to see if size only has 1 this will return the array with one less then size
//third extracts the max and contunues to sift down array untill spot is found returns result
int MaxHeap::extractMax() {
	//checks to see if size is less then or equal to 0 if so throws underflow
	if (size <= 0) throw Underflow();
	//checks to see if size is equal to one if so returns one less then size
	if (size == 1) return arr[--size];
	//if nether of these conditions if the same then will contunes to extractMax and siftdown
	int result = arr[0];
	arr[0] = arr[--size];
	siftdown(0);
	return result;
}
//Purpose: get the value held in the root node
int MaxHeap::getMax() {
	return arr[0];
}
//Purpose: create a node using heapify by splitting the leafs and the parents and sorting
//through each one by sifting down
void MaxHeap::heapify(int* array, int len) {
	arr = array;
	capacity = size = len;
	int half = size / 2 - 1; // the index of the last internal node
	//continures to sift down making sure to put numebrs where they need to be.
	for (int i = half; i >= 0; i--)
		siftdown(i);
}

