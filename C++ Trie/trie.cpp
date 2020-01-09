/*-HW: Extra credit
- Name : Luke Landon
- Compiler Used : Visual Studio
- File type : .cpp
*/
#include "trie.h"
//Purpose: creats an array full of null pointers
Node::Node() {
	for (int i = 0; i < MAX_CHAR; i++)
		children[i] = NULL;
	bisEnd = false;
}
//Purpose:checks to see if it is the end of the prefix
bool Node::isEnd() {
	return bisEnd;
}
//Purpose: inserts a new string into the trie checking each character to put it in the correct prefix
void Node::insert(string s) {
	if (s.length() <= 0)
		return;
	char c = s.at(0);
	if (children[c] == NULL)
		children[c] = new Node();
	if (s.length() == 1)
		children[c]->bisEnd = true;
	else
		children[c]->insert(s.substr(1));
}
//Purpose:adds word to the root of the trie
void Trie::add(string word) {
	root.insert(word);
}

//Purpose: checks to see if the trie contains a word and retusn a bool
bool Trie::contains(string pat) {
	Node* node = root.search(pat);
	if (node != NULL && node->isEnd())
		return true;
	return false;
}
//Purpose:checks to see if the word is a prefix returns a bool
bool Trie::isPrefix(string pat) {
	Node* node = root.search(pat);
	return node == NULL ? false : true;
}
//Purpose: search the trie to see if the word is in the trie
Node* Node::search(string s) {
	if (s.length() == 0)
		return this;
	char c = s.at(0);
	if (children[c] == NULL)
		return NULL;
	return children[c]->search(s.substr(1));
}
//Purpose: prints that sends an empty prefix string
void Trie::print() {
	root.print("");
}

//Purpose: prints the trie contends in a pre order traversal
void Node::print(string word) {
	char child = -1;
	for (int j = 0; j < MAX_CHAR; j++) {
		++child;
		if (children[j] != NULL) {
			children[j]->print(word + child);
			if (children[j]->isEnd()) {
				cout << word + child << endl;
			}
		}
	}
}
//Purpose:whale the sting is not empty and the word has not been found yet then continues to subtract one letter
//if the word is found then it will end the whole loop and return it. if the value is not found because length is 0
//then returns does not exist
string Trie::longestPrefix(string word) {
	bool isfound = false;
	string newword = word;
	while (newword.length() > 0 && !isfound) {
		newword = newword.substr(0, newword.size() - 1);
		isfound = contains(newword);
	}
	if (newword.length() == 0) {
		newword = "Does Not Exist";
	}
	return newword;
}