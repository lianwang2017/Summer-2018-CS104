#include "alistint.h"
#include <iostream>

using namespace std;

int main() {
    AListInt a(3);

    // checks if size is correct
    if(a.cap() == 3) 
    {
        cout << "\033[1;32mPASSED: " << "Correct cap is 3 \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong cap is " << a.cap() << "\033[0m" << endl;
    }

	a.insert(0,2);
    a.insert(1,55);
    // arraylist = {2,55}
    // checks if size is correct
    if(a.size() == 2) 
    {
        cout << "\033[1;32mPASSED: " << "Correct size is 2 \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong size is " << a.size() << "\033[0m" << endl;
    }

    // checks if array list is correct --> arraylist = {2,55} && get function is correct
    if(a.get(0) == 2 && a.get(1) == 55) 
    {
        cout << "\033[1;32mPASSED: " << "Correct get and insert of numbers \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong get or insert" << a.size() << "\033[0m" << endl;
    }

    // checks for inserting in a nonexistent position
    a.insert(1324,1324);
    if(a.size() == 2) 
    {
        cout << "\033[1;32mPASSED: " << "Correct size is 2 \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong size is " << a.size() << "\033[0m" << endl;
    }

	a.insert(0,123);
	if(a.size() == 3) 
    {
        cout << "\033[1;32mPASSED: " << "Correct size is 3 \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong size is " << a.size() << "\033[0m" << endl;
    }

    // checks for correct insertion {123, 2, 55}
    if(a.get(0) == 123 && a.get(1) == 2 && a.get(2) == 55) 
    {
        cout << "\033[1;32mPASSED: " << "Correct get and insert of numbers \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong get or insert" << a.size() << "\033[0m" << endl;
    }

    a.set(1,999);
    // checks if set function works correctly
    if(a.get(0) == 123 && a.get(1) == 999 && a.get(2) == 55) 
    {
        cout << "\033[1;32mPASSED: " << "Correct get and insert of numbers \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong get or insert" << a.size() << "\033[0m" << endl;
    }

	a.remove(2);
    // checks if remove is correct
    if(a.size() == 2) 
    {
        cout << "\033[1;32mPASSED: " << "Correct size is 2 \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong size is " << a.size() << "\033[0m" << endl;
    }

    // checks if remove function works correctly
    if(a.get(0) == 123 && a.get(1) == 999) 
    {
        cout << "\033[1;32mPASSED: " << "Correct get and insert of numbers \033[0m" << endl;
    } 
    else 
    {
        cout << "\033[1;91mFAILED: " << "Wrong get or insert" << a.size() << "\033[0m" << endl;
    }

	return 0;
}