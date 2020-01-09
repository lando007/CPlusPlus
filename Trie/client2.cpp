/*-HW: Extra credit
- Name : Luke Landon
- Compiler Used : Visual Studio
- File type : .cpp
*/
#include <iostream>
#include "trie.h"

using namespace std;

int main()
{
	Trie vocabulary;
	cout << "Type a word ('q' for quit): ";
	string word;
	cin >> word;
	while (word != "q") {
		vocabulary.add(word);
		cout << "The longest prefix is: " << vocabulary.longestPrefix(word) << endl;
		cout << "Type a word ('q' for quit): ";
		cin >> word;
	}
	return 0;
}