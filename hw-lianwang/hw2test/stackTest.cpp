#include "stackint.h"
#include <iostream>

using namespace std;

int main()
{
	StackInt stack;
	int option;
	cout << "What would you like to do?" << endl;
	cout << "1. Insert value onto stack" << endl;
	cout << "2. Return top value on the stack" << endl;
	cout << "3. Delete top value on the stack" << endl;
	cout << "Type 'q' to quit" << endl;
	
	while (cin >> option)
	{
		if(option>3 || option <=0)
		{
			cout << "Invalid option" << endl;
		}
		if(option==1)
		{
			cout << "Enter value:" << endl;
			int x;
			cin >> x;
			stack.push(x);
		}
		if(option==2)
		{
			if(!stack.empty())
			{
				cout << "Top value on the stack is: " << stack.top() << endl;
			}
			else
			{
				cout << "Stack empty" << endl;
			}
		}
		if(option==3)
		{
			stack.pop();
		}
		cout << "What would you like to do?" << endl;
		cout << "1. Insert value(s) onto stack" << endl;
		cout << "2. Return top value on the stack" << endl;
		cout << "3. Delete top value on the stack" << endl;
		cout << "Type 'q' to quit" << endl;
	}

    return 0;
}