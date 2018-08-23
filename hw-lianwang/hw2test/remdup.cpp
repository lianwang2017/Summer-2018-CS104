#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Item
{
    int val;
    Item* next;
};

// reads in the integers from the text file
void readLists(char* filename, Item** head1, Item** head2);
// removes all duplicates in linked list
void removeDuplicates(Item* head);
// combines the two linked list into one
Item* concatenate(Item* head1, Item* head2);

void readLists(char* filename, Item** head1, Item** head2)
{
    ifstream infile(filename);
    string line1; string line2;
    // gets the first line of integers
    getline(infile, line1);
    stringstream ss1(line1);
    int num;
    ss1 >> num;
    Item* temp = new Item;
    temp->val = num;
    head1 = temp;
    while (ss1 >> num)
    {
        Item* temp1 = new Item;
        temp1->val = num;
        head->next = temp1;
    }
    // gets the second line of integers
    getline(infile, line2);
    stringstream ss2(line2);
    int num2;
    ss2 >> num2;
    Item* temp2 = new Item;
    temp2->val = num2;
    head1 = temp2;
    while (ss2 >> num2)
    {
        Item* temp1 = new Item;
        temp1->val = num2;
        head->next = temp1;
    }
}

void removeDuplicates(Item* head)
{

}

Item* concatenate(Item* head1, Item* head2)
{

}


int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        cerr << "Usage ./remdup input_file output_file" << endl;
        return 1;
    }

    Item* head1;
    Item* head2;
    
}
