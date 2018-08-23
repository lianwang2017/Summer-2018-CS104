#include "llistint.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  LListInt * list = new LListInt(); 

  if (list->empty() == true) {
    cout << "\033[1;32mPASSED: " << "List is initialized as empty" << "\033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "List size is not 0" << "\033[0m" << endl;
  }

  cout << "Inserting 10 items where i = i" << endl;
  for(int i = 0; i < 10; i++) {
    list->insert(i, i);
  }

  if (list->size() == 10) {
    cout << "\033[1;32mPASSED: " << "List size is 10" << "\033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "List size is not 10" << "\033[0m" << endl;
  }

  for(int i = 0; i < 10; i++) {
    if(list->get(i) == i) {
    cout << "\033[1;32mPASSED: " << "Correct value at i=" << i << "\033[0m" << endl;
    } else {
      cout << "\033[1;91mFAILED: " << "Value at i=" << i << "is wrong" << "\033[0m" << endl;
    }
  }

  cout << "Inserting 500 at i=0" << endl;
  list->insert(0, 500);
  if(list->get(0) == 500) {
    cout << "\033[1;32mPASSED: " << "Correct value at i=0 \033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "Wrong value at i=0 \033[0m" << endl;
  }

  cout << "Inserting 300 at i=5" << endl;
  list->insert(5, 300);
  if(list->get(5) == 300) {
    cout << "\033[1;32mPASSED: " << "Correct value at i=5 \033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "Wrong value at i=5 \033[0m" << endl;
  }

  cout << "Appending 800" << endl;
  list->insert(list->size(), 800);

  if(list->get(list->size() - 1) == 800) {
    cout << "\033[1;32mPASSED: " << "Correct value at i=size_-1 \033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "Wrong value at i=size_-1 \033[0m" << endl;
  }

  cout << "Removing item at i=0" << endl;
  list->remove(0);
  if(list->get(0) == 0) {
    cout << "\033[1;32mPASSED: " << "Correct value at i=0 \033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "Wrong value at i=0 \033[0m" << endl;
  }

  cout << "Removing item at i=1" << endl;
  list->remove(0);
  if(list->get(1) == 2) {
    cout << "\033[1;32mPASSED: " << "Correct value at i=1 \033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "Wrong value at i=1 \033[0m" << endl;
  }

  cout << "Appending 800" << endl;
  list->insert(list->size(), 900);

  cout << "Removing item at i=size_-1" << endl;
  list->remove(list->size() - 1);
  if(list->get(list->size() - 1) == 800) {
    cout << "\033[1;32mPASSED: " << "Correct value at i=size_-1 \033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "Wrong value at i=size_-1 \033[0m" << endl;
  }

  cout << "Removing all items" << endl;
  int currentListSize = list->size();
  for(int i = 0; i < currentListSize; i++) {
    list->remove(list->size() - 1);
  }

  if (list->empty() == true) {
    cout << "\033[1;32mPASSED: " << "List is empty" << "\033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "List size is not empty" << "\033[0m" << endl;
  }

  cout << "Appending 800" << endl;
  list->insert(list->size(), 800);
  if(list->get(list->size() - 1) == 800) {
    cout << "\033[1;32mPASSED: " << "Correct value at i=0 \033[0m" << endl;
  } else {
    cout << "\033[1;91mFAILED: " << "Wrong value at i=0 \033[0m" << endl;
  }

  // Clean up memory.
  delete list;
}