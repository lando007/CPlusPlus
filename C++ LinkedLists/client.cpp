//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: Luke Landon
//Complier:  Visual Studio
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "llist.h"

void caseOne()
{
	cout << "CASE 1:------------------- " << endl;
	llist L;   // this is my list
	int x;  // to hold a removed element

	//1 check empty and report the result  
	cout << 1 << ": Checking to see if the list is empty: " << endl;
	if (L.isEmpty()){
		cout << "List is Empty" << endl;
	}
	else {
	cout << "List is not empty" << endl;
    }
		//2 display the list  
		cout << 2 << ": Displaying the list " << endl;
		L.displayAll();

		//3 add 4 integers 1,2,3,4    
		cout << 3 << ": Adding 1, 2, 3, 4 to the rear of the list " << endl;
		L.addRear(1);
		L.addRear(2);
		L.addRear(3);
		L.addRear(4);

		//4 display the list  
		cout << 4 << ": Displaying the list" << endl;
		L.displayAll();

		//5 remove from front twice (and display the elements removed)
		cout << 5 << ": Deleting from the front of the list twice " << endl;
		L.deleteFront(x);
		cout <<"The number deleted is: " << x << endl;
		L.deleteFront(x);
		cout << "The number deleted is: " << x << endl;

		//6 display the list
		cout << 6 << ": Displaying the list" << endl;
		L.displayAll();

		//7 check empty and report the result 
		cout << 7 << ": Checking to see if the list is empty " << endl;
		if (L.isEmpty()){
			cout << "the List is Empty" << endl;
		}
		else {
			cout << "The List is Not Empty" << endl;
		}
		
		//8 remove from the rear twice (display the element removed)
		cout << 8 << ": Deleting twice form the rear of the list" << endl;
		L.deleteFront(x);
		cout << "The number deleted is: " << x << endl;
		L.deleteFront(x);
		cout << "The number deleted is: " << x << endl;

		//9 check empty again and report the result
		cout << 9 << ": Checking to see if the list is empty " << endl;
		if (L.isEmpty()) {
			cout << "the List is Empty" << endl;
		}
		else {
			cout << "The List is Not Empty";
		}
}//end of case 1 

void caseTwo()
{
	cout << "Case 2: -----------------------" << endl;
	llist L2;  // another list
	int x;   // to hold the removed element 
	int c = 1;  // displayed step number

	// 1.add to front once   (element 5)
	cout << c << ": Add 5 to front of list- " << endl; c++;
	L2.addFront(5);

		// 2.add to front again  (element 4)
		cout << c << ": Add 4 to front of list- " << endl; c++;
	L2.addFront(4);

		// 3.delete Front
		cout << c << ": Deleting from front- " << endl; c++;
		L2.deleteFront(x);

		// 4.add to rear 3 times (elements 6,8,9)
		cout << c << ": Add 6, 8, 9 to Rear of list- " << endl; c++;
	L2.addRear(6);
	L2.addRear(8);
	L2.addRear(9);

		// 5. display all
		cout << c << ": Display All- " << endl; c++;
	L2.displayAll();

		// 6.add before the 1st  (element 4) . 4 5 6 8 9
		cout << c << ": Add 4 to location 1- " << endl; c++;
	L2.addbeforeIth(1, 4);

		// 7.add before the 4th  (element 7) . 4 5 6 7 8 9
		cout << c << ": Add 7 to location 4- " << endl; c++;
	L2.addbeforeIth(4, 7);

		// 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
		cout << c << ": Add 10 to location 7- " << endl; c++;
	L2.addbeforeIth(7, 10);

		// 9.add before the 9th  (element 12) . error (out of range)
		cout << c << ": Try to Add 12 to location 9 If out of range display message- " << endl; c++;
		try {
			L2.addbeforeIth(9, 12);
		}
		catch (llist::OutOfRange) {
			cout << "The number you provided was out of range to index on the list" << endl;
		}
	// 10.add before the 0th (element 0) . error (out of range)
	cout << c << ": Try to Add 0 to location 0 If out of range display message- " << endl; c++;
	try { L2.addbeforeIth(0, 0); }
	catch (llist::OutOfRange) {
		cout << "the index you provided was out of range of the list" << endl;
	}
	// 11.displayAll
	cout << c << ": Display All- " << endl; c++;
	L2.displayAll();

		// 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
		cout << c << ": Deleting number in location 1- " << endl; c++;
		L2.deleteIth(1, x);
		cout << "The number deleted is: "<< x << endl;

		// 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
		cout << c << ": Deleting Number in location 6- " << endl; c++;
		L2.deleteIth(6, x);
		cout << "The number deleted is: " << x << endl;

		// 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
		cout << c << ": Deleing number in location 3- " << endl; c++;
		L2.deleteIth(3, x);
		cout << "The number deleted is: " << x << endl;

		// 15.delete Ith I==5 . error (out of range)
		cout << c << ": Try to delete number in location 5 If out of range display message- " << endl; c++;
		try { L2.deleteIth(5, x); }
	catch (llist::OutOfRange) { 
		cout << " The number you provided was out of range to index on the list" <<endl;
	}
	// 16.delete Ith I==0 . error (out of range)
	cout << c << ": Try to delete number in location 0 If out of range display message- " << endl; c++;
	try { L2.deleteIth(0, x); }
	catch (llist::OutOfRange) { 
		cout << "the index you provided was out of range of the list" << endl;
		}
	// 17.displayAll
	cout << c << ": Displaying all- " << endl; c++;
	L2.displayAll();

		// 18.delete from rear until it is empty (indicate the elements removed)
		cout << c << ": Deleting from rear untill list is empty- " << endl; c++;
		while (!L2.isEmpty()) {
			L2.deleteRear(x);
			cout <<" The number deleted is: " << x << endl;
		}

		// 19.displayAll  
		cout << c << ": Displaying everything is list-  " << endl; c++;
		L2.displayAll();

}//end of case 2

void caseThree()
{
	cout << "Case 3:-------------------- " << endl;
	llist L3;
	int x;  // to hold the removed element

	// 1.add before the 0th . error (out of range)
	cout << 1 << ": Trys to add number before element 0 if unable catch out of range- "<< endl;;
	try { L3.addbeforeIth(0, 0); }
	catch (llist::OutOfRange) { 
		cout << "The number you provided was out of range to index on the list" << endl;
	}
	//2.delete front . error (underflow)
	cout << 2 <<": Trys to delete from the front if unable catch displays underflow- "<< endl;
	try { L3.deleteFront(x); }
	catch (llist::Underflow) { 
		cout << "the list does not contain any elements and is empty." << endl;
	}
}   //end of case 3

void caseFour()
{
	cout << "Case 4:------------------------ " << endl;
	llist L4;
	int x;  // to hold the removed element

	//   1.delete 2nd . error (out of range)
	cout << 1 << ": trys to delete number in location 2 if unable catch out of range- "<< endl;
	try { L4.deleteIth(2, x); }
	catch (llist::OutOfRange) { 
		cout << "The index is out of range of the list" << endl;
	}
	//    2.delete rear . error (underflow)
	cout << 2  << ": Trys to delete from rear if unable catch underflow"<< endl;
	try { L4.deleteRear(x); }
	catch (llist::Underflow) {
		cout << " The list does not contain any elements." << endl;
	}
} // end of case 4


//PURPOSE of the Program: **
//Algorithm/Design: 4 test cases are divided into 3 functions and **
int main()
{
	int selection; // this will indicate what the user wants to do

	do
	{
		cout << endl << "MENU: These are your options: " << endl << endl;
		cout << "   (1) Case 1  " << endl;
		cout << "   (2) Case 2  " << endl;
		cout << "   (3) Case 3  " << endl;
		cout << "   (4) Case 4 " << endl;
		cout << "    Enter ( 0 ) to quit " << endl;
		cout << "===>";

		cin >> selection;

		switch (selection)
		{
		case 1: caseOne(); break;
		case 2: caseTwo(); break;
		case 3: caseThree(); break;
		case 4: caseFour(); break;
		}
	} while (selection != 0);

}// end of main

