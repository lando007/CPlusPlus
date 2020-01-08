//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Luke Landon
//Complier:  Visual Studio
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

//The purpose: this is the defult constructor for llist
//makes front = null and rear = null
//sets count = 0
llist::llist() {
	Front = NULL;
	Rear = NULL;
	Count = 0;
}
//The purpose: this is the deconstructor of llist
//deletes from the front untill the llist is empty
llist::~llist() {
	el_t temp;
	while (!isEmpty())
		 deleteFront(temp);
	cout << "calling the llist descructor:";
}


//The Purpose: checks to see if the list is empty 
bool llist::isEmpty() {
	//if front and rear both equal null and count is set to 0 then returns true
	if ((Front == NULL) && (Rear == NULL) && (Count == 0)  )
		return true;
	//else list is not empty and returns false
	else{ 
		return false; 
	}
}

//The purpose: to display all of the elements in the node or if it is empty display that
//The way this is done is if the list is empty then it will print the current list is empty
//else will go through a while loop that will continue to print and incrament p untill it reaches null.
void llist::displayAll() {
	//makes a pointer to to get the front of the list
	Node *p = Front;
	//if list is emtpy the display:
	if (isEmpty()) {
		cout << "The current list is empty" << endl;
	}
	//else list is not empty printing out p and setting next to p untill p is null
	else {
		while (p != NULL) {
			cout << "[" << p->Elem << "]";
			p = p->Next;
		}
		cout << endl;
	}
}
  
//purpose: of this is to add to the rear of the linked list
//parameter: is NewNum which is the element assignmed to the node p
//This has two cases: the 1st case is a special case that if the first node
//you need to create a new node and have front and rear point to it
//place NewNum and incrament count;
//The 2nd case adds a new node to the rear and put NewNum in the element of the new node 
//then count is updated
void llist::addRear(el_t NewNum){
	//special case this is when there are no elements in list
	//new node p is created and NewNum is set to the element
	//sets rear and front to p and makes next null
	if (Count == 0) {
		Node *p = new Node;
		p->Elem = NewNum;
		Front = p;
		Rear = p;
		Rear->Next = NULL;
		}
	//2nd this is when there are allready node is the list
	//node p is created and NewNum is assigned to p element
	//rear next points to p and rear points to p.
	//sets rear next pointing to null
	else {
		Node *p = new Node;
		p->Elem = NewNum;
		Rear->Next = p;
		Rear = p;
		Rear->Next = NULL;
		}
	//after ether cases finishes count is incramented
	Count++;
	
}
//Purpose: this adds an element to the front of a linkedlist
//Parameter: NewNum will be the element added to the front of the node
//Two cases: case 1 case is to check and see if the list is empty
//if not then NewNum is assinged to a new node x and then front a rear
//is set to point at it then rear next is set to null
//case 2 is when there are allready nodes in the list just creates a new node x
//sets front to x next and x to front. at the end New num is set to x element
//after ether case is done count is updated
void llist::addFront(el_t NewNum)
{
	//case 1: creates a new node x
	//front and rear point to x
	//rear pointer is set to null
	if (Count == 0) {
		Node* x = new Node;
		x->Elem = NewNum;
		Front = x;
		Rear = x;
		Rear->Next = NULL;
	}
	//case 2: new node x is created and x next is set to front
	//front is set to x and x element is set to NewNum
	else {
		Node* x = new Node;
		x->Next = Front;
		Front = x;
		x->Elem = NewNum;
	}
	//count is updated after ether case is run
	Count++;
}
		 
//Purpose: this deletes the front node in the list
//Parameter: OldNum which is set to hold the element deleted
//3 Cases are checked:
//The first case is to check and see if the list is empty if it is throw underflow
//The Second case it to see if there is only one node if this is the case
//sets oldnum to front element deletes front and sets front and rear to null decresseing count
//The third case is when there are more then one node in the list and deletes the front putting 
//the number in oldnum to be passed back and decressing count 
void llist::deleteFront(el_t& OldNum) {
	//checks to see if list is empty is so throws underflow
	if (isEmpty())
	{
		throw Underflow();
	}
	//checks to see if there is only one element in the list if so returns number as oldnum
	//sets front and rear to null and decreases count
	else if(Count == 1) {
		OldNum = Front->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}
	//this is when there are more then one node in the list
	//front is held in oldnum. createsa new node that hold front to next deletes front
	//and sets new node to front decreases count
	else {
		OldNum = Front->Elem;
		Node* Second = Front->Next;
		delete Front;
		Front = Second;
		Count--;
	}
}
		 
//Purpose: the purpose is to delete the node at the rear of the list
//Parameter: OldNum which is used to hold the deleted node
//3 Cases: The first case is to check and see if the list is empty if so throw underflow
//The second case is when there is only one node in the list return node that was deleted
//and set the front and rear to be null
//The third case is when there is more then 1 node in the list which returns the oldnum
// that hold the node deleted and sets rear next to null
void llist::deleteRear(el_t& OldNum)
{
	//Checks to see if list is empty if so throws underflow
	if (isEmpty()) {
		throw Underflow();
	}
	//checks to see if there is only one node in the list if so sets old num to deleted node 
	//sets front and rear to null decreasing count
	else if (Count == 1) {
		OldNum = Rear->Elem;
		delete Front;
		Front = NULL;
		Rear = NULL;
		Count--;
	}
	//sets oldnum to rear element going to be deleted
	//used if there is more the one node in the list if so makes a pointer p that points to front
	//uses while loop to acces last node deletes rear and sets node p to rear making rear next null
	//decreases count 
	
	else
	{
		OldNum = Rear->Elem;
		Node* p = Front;
		//while loop used to access rear pointer by looping through list
		while (p->Next != Rear) {
			p = p->Next;
		}
		delete Rear;
		Rear = p;
		Rear->Next = NULL;
		Count--;
	}
}
//Purpose: This deletes the element at point I in the list
//Parameter: OldNum to hold variable that is deleted 
//4 Cases:
//1st Case: checks to see if the value is withing the scope if not throw out of range
//2nd Case: calls delete front when I is the first node
//3rd Case: checks to see if I is set to count if so deletes rear
//4th case deletes the I node and count is then updated
void llist::deleteIth(int I, el_t& OldNum) {
	//used if out of range
	if (I > Count || I < 1){
		throw OutOfRange();
	}
	//used if I is the first node in the list
	else if (I == 1){
		deleteFront(OldNum);
	}
	//used if I is the last node in the list
	else if (I == Count) {
		deleteRear(OldNum);
	}
	//creates two nodes one the points to front and another to hold value
	//loops to point to the I node and get the pointer before that
	//sets the l next node to p1 next and set odlnum to p1 element
	//delete p1 and decrease count
	else{
		Node* p1 = Front;
		Node* l = new Node;
		for (int j = 1; j < I - 1; j++) {
			l = p1;
			p1 = p1->Next;
		}
		l->Next = p1->Next;
		OldNum = p1->Elem;
		delete p1;
		Count--;
	}
}
//Purpose: Add a node before the I position
//Paramenter: NewNum which is the element added
//4 Cases:
//1st Case: if the I value is out of bounds then out of range is thrown
//2nd Case: if I is the first node then call addFront
//3rd Case: of I is the count + 1 then call addRear
//4th Case: add newnum to the right of the I node and update count
void llist::addbeforeIth(int I, el_t newNum) {
	//check out of range if so throw out of range
	if (I > Count + 1 || I < 1) {
		throw OutOfRange();
	}
	//ches to see if I is first element is so addFront
	else if (I == 1) {
		addFront(newNum);
	}
	//checks to see if I = count +1 if so then addRear
	else if (I == Count + 1) {
		addRear(newNum);
	}
	//creates two nodes one for Front and another one l
	//loop to the I - 1 node and let l next to p1
	// p1 element is set to newnum
	//p1 next is set to p and coutn is incramented
	else {
		Node* p1 = new Node; 
		Node* p = Front; 
		Node* l = new Node; 
		//loop to the point before I
	for (int k = 1; k <= I - 1; k++){
			l = p;
			p = p->Next;
		}
		l->Next = p1;
		p1->Elem = newNum;
		p1->Next = p;
		Count++;
	}
}
		 