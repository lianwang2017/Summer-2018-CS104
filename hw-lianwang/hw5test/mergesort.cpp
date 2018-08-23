#include <iostream>
#include <vector>
using namespace std;

void divide(vector<int> &array, int start, int end);

void merge(vector<int> &array, int first, int second, int mid);

void divide(vector<int> &array, int start, int end)
{
    if (start == end)
    {
        return; // end recursion when size is 1
    }
    else
    {
        int mid = (start + end) / 2; // find midpoint
        divide(array, start, mid); // recurse through first half
        divide(array, mid+1, end); // recurse through second half
        merge(array, start, end, mid);
    }

}

void merge(vector<int> &array, int start, int second, int mid)
{
    // x keeps track of first array and y keeps track of second array
    int x = 0; int y = 0; 

    // create copy of left array
    vector<int> left;
    for (int i = start; i <= mid; i++)
    {
        left.push_back(array[i]);
    }

    // create copy of right array
    vector<int> right;
    for (int i = mid+1; i <= second; i++)
    {
        right.push_back(array[i]);
    }

    // ACTUALLY MERGING NOW
    while (x < left.size() && y < right.size())
    {
        if (left[x] > right[y]) // if first is greater than second
        {
            array[start] = right[y];
            start++;
            y++;
        }
        else // if first is less than second
        {
            array[start] = left[x];
            start++;
            x++;
        }
    }

    // checking for which array is left over
    if (x == mid+1) // if second array is all larger than first array --> COPYING ALL of LEFT SIDE
    {
        for (int i = y; i < right.size(); i++)
        {
            array[start] = right[i];
            start++;
        }
    }
    else // if first array is all larger than second array --> COPYING ALL of LEFT SIDE
    {
        for (int i = x; i < left.size(); i++)
        {
            array[start] = left[i];
            start++;
        }
    }

    // Comment
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << ' ';
    }
    cout<< endl;
}

int main()
{
    cout << "User input (enter any character to end): ";
    int input;
    vector<int> list;
    while (cin >> input)
    {
        list.push_back(input);
    }
    
    // for checking if cin worked
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    int start = 0;
    int end = list.size()-1;
    divide(list, start, end);

    // prints out the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

}