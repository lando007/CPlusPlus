//luke landon
//200129064
//luke.e.landon@gmail.com
#include <iostream>
using namespace std;
//creats a new and the pointer to the next
struct Node
{
	int num;
	Node* next;
};
//class to run all the methods in

class LinkedList
{
public:

	int num;
	Node* head1;
	LinkedList();
	void insertHead(int num);
	void printList();
};
//Checks to see if that number value is in the current node 
//if it is not then it will return true if the num is the same
//as the next num 
bool contains(Node* headNode, int number) {
	Node* hn = headNode;
	while (hn != NULL) {
		if (hn->num == number)
			return false;
		hn = hn->next;
	}
	return true;
}
//Combines linkedList LB into LA
//Also checks to see if LB is in LA that way
//there are no numbers that are the same
//calls on contains method to do this
//if contains 
void unionLL(Node* LA, Node* LB) {
	Node* list1 = LA;
	Node* list2 = LB;
	while (list2 != NULL) {
		if (contains(LA, list2->num)) {
			Node* node = new Node();
			node->num = list2->num;
			while (list1->next != NULL) {
				list1 = list1->next;
			}
			list1->next = node;
		}
		list2 = list2->next;
	}
}
//Compares Values of LA and LB and writes them to LC
//first will check to see if LB or LA is bigger.
//This will put the bigger number and use that first on LC
//Second will continue to check if each value is not NULL for both 
//LA and LB. 
//Third will check to see which value is bigger LA or LB and take 
//from one of them incramint it untill ether LB or LA is NULL.
//After this is done will finishes the oposits LinkedList untill equals NULL.
void mergeLL(Node* LA, Node* LB, Node* LC)
{
	Node* list1 = LA;
	Node* list2 = LB;
	Node* list3 = LC;
	if (list1->num > list2->num) {
		list3->num = list2->num;

		list2 = list2->next;
	}
	else if (list1->num <= list2->num) {
		list3->num = list1->num;

		list1 = list1->next;
	}
	while (list1 && list2 != NULL) {

		Node* temp = new Node();

		if (list1->num <= list2->num) {
			temp->num = list1->num;
			list3->next = temp;
			list1 = list1->next;
			list3 = list3->next;
			if (list1 == NULL) {
				while (list2 != NULL) {
					Node* temp2 = new Node();
					temp2->num = list2->num;
					list3->next = temp2;
					list2 = list2->next;
					list3 = list3->next;
				}
			}
		}

		else if (list1->num > list2->num) {
			temp->num = list2->num;
			list3->next = temp;
			list2 = list2->next;
			list3 = list3->next;
			if (list2 == NULL) {
				while (list1 != NULL) {
					Node* temp3 = new Node();
					temp3->num = list1->num;
					list3->next = temp3;
					list1 = list1->next;
					list3 = list3->next;
				}
			}
		}
	}
}

//Creates a Linked List
LinkedList::LinkedList() {
	this->num = 0;
	this->head1 = NULL;
}
//Inserts a number to the head of the node
void LinkedList::insertHead(int num) {
	Node* node = new Node();
	node->num = num;
	node->next = this->head1;
	this->head1 = node;
}


//Prints Linked List from head forward
void LinkedList::printList() {
	Node* head = this->head1;
	int i = 1;
	while (head) {
		cout << " " << head->num;
		head = head->next;
		i++;
	}
}


//main function to run all code
int main(int argc, char const* argv[])
{

	LinkedList* LA = new LinkedList();
	LinkedList* LB = new LinkedList();
	LinkedList* LA2 = new LinkedList();
	LinkedList* LB2 = new LinkedList();
	LinkedList* LC = new LinkedList();
	LA->insertHead(11);
	LA->insertHead(8);
	LA->insertHead(5);
	LA->insertHead(3);

	LB->insertHead(24);
	LB->insertHead(22);
	LB->insertHead(11);
	LB->insertHead(8);
	LB->insertHead(6);
	LB->insertHead(2);

	LA2->insertHead(11);
	LA2->insertHead(8);
	LA2->insertHead(5);
	LA2->insertHead(3);
	LB2->insertHead(24);
	LB2->insertHead(22);
	LB2->insertHead(9);
	LB2->insertHead(8);
	LB2->insertHead(6);
	LB2->insertHead(2);
	LC->insertHead(NULL);

	cout << "the first linklist numbers are " << endl;
	LA->printList();
	cout << " " << endl << "the second set of numbers are" << endl;
	LB->printList();
	unionLL(LA->head1, LB->head1);
	cout << endl << endl;
	cout << "The union of both the lists is: " << endl;
	LA->printList();
	cout << endl << "the first linklist numbers are " << endl;
	LA2->printList();
	cout << " " << endl << "the second set of numbers are" << endl;
	LB2->printList();
	mergeLL(LA2->head1, LB2->head1, LC->head1);
	cout << "     " << endl << "Merge of both LA and LB is: " << endl;
	cout << endl;
	LC->printList();
	cout << endl;

	system("pause");


}