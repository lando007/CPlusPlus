/*-HW: Extra credit
- Name : Luke Landon
- Compiler Used : Visual Studio
- File type : .h
*/
#ifndef TRIE_H
#define TRIE_H

#define MAX_CHAR 256

#include <string>

#include <iostream>
using namespace std;
class Node
{
private:
	Node* children[MAX_CHAR];   // array of MAX_CHAR qty Node*'s
	bool bisEnd;
public:

	Node();//constuctor
	bool isEnd();// checks to see if the current value is the end of a prefix if it is then it will return true
	void insert(string suffix);//insters a string into trie
	void print(string);//prints the content of each string in the trie 
	Node* search(string pat);//searches to determine if the given string exists in the trie

};

class Trie
{
private:
	Node root;//node root
public:
	void print();//used to pring the contents of the trie
	void add(string word);//adds the string into the trie
	bool contains(string pat);//checks to see if the given string exitst in the trie
	bool isPrefix(string pat);//checks to see if the given string into the trie and retuns true if exists
	string longestPrefix(string);//finds the longest prefix that is in the tree involving the words of the string

};
#endif
