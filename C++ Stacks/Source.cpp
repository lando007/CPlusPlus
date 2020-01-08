//Luke Landon
//luke.e.landon@gmail.com
//ID: 200129064
#include <iostream>
using namespace std;
// sets stack size to 20
#define STACK_SIZE 20
//creates a class of aray stack that hold push, pop, topEl(top element in stack)
//and overflow and underflow exeptions
class ArrayStack {
private:
	int top;
	char Elm[STACK_SIZE];
public:
	ArrayStack();
	void push(char d);
	char pop();
	char topEl();
	class Overflow {
	};
	class Underflow {
	};
};
class invalidExpression {};
double evalExpression(const char* exp);
char precede(char a1, char b1);
char operate(char a, char tempOperator, char b);
//method checks the temp char in the const char exp and checks top element in OPTR to make sure they are both not #
//checks to see if temp char holds an expression if so pushes it to OPND and incraments temp
//if this is not the case passes temp and topEl to precede and check to see if they are 1,0,or -1
//if 1 is selected OPTR has temp pushed to it and incraments the const char exp
//if 0 is selected then OPTR gets a char poped and incraments to next const char exp
//if -1 is selected OPTR has one pop and OPND has two poped 
//these falues are passed to the operate method and the return value is pushed to OPND
//at the end the returned type needs to be cased backed to ASkii and subtraced value to read correctly
double evalExpression(const char* exp) {
	
	ArrayStack OPND;
	ArrayStack OPTR;
	
	int t = 0;
	char temp = exp[t];
	OPTR.push(temp);
	t++;
	temp = exp[t];
	while (!((temp == '#') && (OPTR.topEl() == '#')))     //dont know if this will work?
	{
		if (temp != '#' && temp != '-' && temp != '+' && temp != '/' && temp != '(' && temp != ')' && temp !='*') {
			OPND.push(temp);
			t++;
			temp = exp[t];
		}
		else if(precede(OPTR.topEl() , temp) == 1) {
			OPTR.push(temp);
			t++;
			temp = exp[t];
			
			
		}
		else if (precede(OPTR.topEl(), temp) == 0) {
			OPTR.pop();
			t++;
			temp = exp[t];

		}
		else if (precede(OPTR.topEl(), temp) == -1) {
			char tempOperator = OPTR.pop();
			char b = OPND.pop();
			char a = OPND.pop();
			OPND.push(operate(a, tempOperator, b));

		}
	}
	
	
	
	return (double)OPND.topEl() - 48;
}
//preceed takes both char passed and compares the case to which they belong
//depending on relationship the case will equal 1,0, or -1
//if the expression does not exist it will throw and exeption
char precede(char a1, char b1) {
	char a = a1;

	char b = b1;

	if (a == '+') {
		switch (b) {
		case '*':
		case '/':
		case '(':
			return 1;
			break;
		default:
			return -1;
			break;
		}
	
	}
	else if(a == '-')
		switch (b) {
		case '*':
		case '/':
		case '(':
			return 1;
			break;
		default:
			return -1;
			break;
		}
	else if(a == '*')
		switch (b) {
		case '(':
		
			return 1;
			break;
		default:
			return -1;
			break;
		}
	else if(a == '/')
		switch (b) {
		case '(':
			return 1;
			break;
		default:
			return -1;
			break;
		}
	else if(a == '(' )
		switch (b) {
		case ')':
			return 0;
			break;
		case '#':
			throw invalidExpression();
		default:
			return 1;
			break;
		}
	else if(a == ')')
		switch (b) {
		case '(':
			throw invalidExpression();;
			
		default:
			return -1;
			break;
		}
	else if(a == '#')
		switch (b) {
		case '#':
			return 0;
			break;
		case ')':
			throw invalidExpression();
		default:
			return 1;
			break;

		}

}
ArrayStack::ArrayStack() {
	top = -1;
}
//operate takes 3 char casts them and subtracts the askii value from them
//they are then depending on the operator added, subtracted, multiplied, or divided
char operate(char a, char tempOperator, char b) {
	
	double ia = (double)a - 48;
	
	double ib = (double)b - 48;
	
	double ic = 0;

	if (tempOperator == '*') {
		ic = ia * ib;
	}
	else if (tempOperator == '/') {
		ic = ia / ib;
	}
	else if (tempOperator == '+') {
		ic = ia + ib;
	}
	else if (tempOperator == '-') {
		ic = ia - ib;
	}
	else {
		throw invalidExpression();
	}
	return (char)ic + 48;

	

}
//pushes char to top of stack if full throws overflow
void ArrayStack::push(char d) {

	if (top < STACK_SIZE - 1) {
		top++;
		Elm[top] = d;
	}
	else {
		throw Overflow();
	}
}
//takes character out of stack if there is no more to take out throws underflow
char ArrayStack::pop() {
	if (top >= 0) {
		return Elm[top--];
		
	}
	else {
		throw Underflow();
	}
}

//checks to see what the value of the top element is if there is none throws underflow
char ArrayStack::topEl() {
	if (top >= 0) {
		return Elm[top];
	}
	else {
		throw Underflow();
	}
}
//main program with a const char* which is passed to evalExpression with a try and catch statment to make sure to catch expetions
int main() {
	
	
	const char* equation = "#3+(7*6)#";
	if (equation == NULL)
	{
		cout << "Please Enter an Equation";
		exit;
			
	}
	else {
		try {
			cout << evalExpression(equation);
		}
		catch (ArrayStack::Underflow) {
			cout << "stack underflow exeption";

		}
		catch (ArrayStack::Overflow) {

			cout << "stack overflow exeption";
		}
		catch (invalidExpression) {
			cout << "invalidExpresion ";
		}
	}
	
	cout << endl;
	
	

}

