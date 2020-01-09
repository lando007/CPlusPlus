/*
-HW:Project 8
-Name: Luke Landon
-Compiler Used:Visual Studio
-File type: .h
*/
#include <iostream>
#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std;

class Entry {
	string name; //string used to store the name
	string phone;//string used to store the phone number of the person
	float salary; // float used to store the salary of the person
public:
	//enters the name phone and salery and connects it with a pointer to each
	Entry(string name, string phone, float salary) {
		this->name = name;
		this->phone = phone;
		this->salary = salary;
	}
	string getKey() { return name; }//returns name
	string getPhone() { return phone; }//returns phone 
	float getSalary() { return salary; } // returns salary
	void setKey(string str) { name = str; } // sets the name to the key
};

class HashMap {
public:
	//exception used if there is an over flow
	class Overflow {};
	//creats a hashmap with int size
	HashMap(int size);
	//deconstructs hashmap
	~HashMap();
	//passes in the unsigned long and passes key to myhash
	unsigned long myHash(string str);
	//puts the pointer to e in the array
	void put(Entry* e);
	//pointer to get the key 
	Entry* get(string key);
	//pointer to remove the key
	Entry* remove(string key);
protected:
	//pointer to the pointer table
	Entry** table;
	//creats the size of the array
	int size;
};
#endif
