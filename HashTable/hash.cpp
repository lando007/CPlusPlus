/*
-HW:Project 8
-Name: Luke Landon
-Compiler Used:Visual Studio
-File type: .cpp
*/
#include <iostream>
#include "hash.h"
//Purpose: Create a hash map with the size setting each element in the arry to NULL
HashMap::HashMap(int size) {
	this->size = size;
	table = new Entry * [size];
	//loops through the array setting each element to null
	for (int i = 0; i < size; i++)
		table[i] = NULL;

}
//Purpose: Deconstruct the Array by looping through the elements
HashMap::~HashMap() {
	//checks to see if i is less then size if so continues untill i is not
	for (int i = 0; i < size; i++)
		//if it is and the element is not null then deletes table i
		if (table[i] != NULL)
			delete table[i];
	delete[] table;
}
//Purpose: Removes the String key and entering empty into the stop for the name and phone numebr
Entry* HashMap::remove(string key) {
	int index = myHash(key) % size;
	int startIndex = index;
	//checks to see if the value is not null and the table index does not equal key
	while (table[index] != NULL && table[index]->getKey() != key) {
		index = (index + 1) % size;
		//used if index equals the start index and returns null
		if (index == startIndex) return NULL;
	}
	//puts the table index into the pointer for e then delets e
	Entry* e = table[index];
	delete e;
	//sets table index with a new entry which is filled with empty and a value of 0
	table[index] = new Entry("empty", "empty", 0);
	return e;
}
//Purpose: Get the String key and returns the values inside the element in the array
Entry* HashMap::get(string key) {
	int index = myHash(key) % size;
	int startIndex = index;
	//while the table index does not equal null and the table index get key does not equal key will continue to loop
	while (table[index] != NULL && table[index]->getKey() != key) {
		index = (index + 1) % size;
		//if index equals the start of the index it returns null
		if (index == startIndex) return NULL;
	}
	return table[index];
}
//Purpose: Take the pointer to entry e and stops that in key. Then key is passed to myhash and put in index
//This value is then put in an empty spot in the array
void HashMap::put(Entry* e) {
	string key = e->getKey();
	int index = myHash(key) % size;
	int startIndex = index;
	//loops for an empty stop in the array to put index
	while (table[index] != NULL && table[index]->getKey() != key && table[index]->getKey() != "empty") {
		index = (index + 1) % size;
		//throws over flow if index equals startindex
		if (index == startIndex) throw Overflow();
	}
	table[index] = e;
}
//used to take the data held in str and store it into a smaller value using hashing
unsigned long HashMap::myHash(string str) {
	const char* cstr = str.c_str();
	unsigned long hash = 5381;
	int c;
	//continues to cut down the long values passed to a simple hash variable
	while (c = *cstr++)
		hash = hash * 33 + c;
	return hash;
}


