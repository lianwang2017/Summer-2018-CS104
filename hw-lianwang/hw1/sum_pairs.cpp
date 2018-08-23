#include <iostream>
#include <fstream>

using namespace std;

// num1 is the start of array1
// num2 is the end of array1
// a2 is the start of array2
void add(int num1, int num2, int* array1, int* array2);

void add(int num1, int num2, int* array1, int* array2)
{
	if (num1 == num2) // case for odd numbers
		array2[num1] = 2*array1[num1];
	else if (num1 > num2) // case for even numbers
		return;
	else
	{
		int sum = array1[num1] + array1[num2];
		array2[num1] = sum;
		return add(++num1, --num2, array1, array2);
	}
}

int main(int argc, char* argv[])
{
	// checks for correct number of arguments
	if (argc < 2)
	{
		cout << "Error. Usage: ./sum_pairs in_file.txt out_file.txt" << endl;
		return 1;
	}

	// checks for input file
	ifstream infile(argv[1]);
	if (infile.fail())
	{
		cout << "Error. Unable to open file: " << argv[1] << endl;
		return 1;
	}

	int num = 0;
	infile >> num;
	if (infile.fail() || num == 0)
	{
		cout << 0 << endl;
		return 1;
	}

	// reads in the integers into an array
	int* list = new int[num];
	for (int i = 0; i < num; i++)
	{
		int temp;
		infile >> temp;
		list[i] = temp;
	}

	// checking for correct input
	/*for (int i = 0; i < num; i++)
	{
		cout << list[i] << endl;
	}*/

	// creates a new dynamic array for sum of pairs
	int nsize;
	if (num%2 == 0)
	{
		nsize = num/2;
	}
	else
	{
		nsize = num/2 +1;
	}
	int* sum = new int[nsize];

	// initialize new array for sums
	for (int i = 0; i < nsize; i++)
	{
		sum[i] = 0;
	}

	// implement add function
	add(0, num-1, list, sum);

	// checks for correct summing of pairs
	/*cout << "Sum of pairs" << endl;
	for (int i = 0; i < nsize; i++)
	{
		cout << sum[i] << endl;
	}*/

	ofstream outfile(argv[2]);
	for (int i = 0; i < nsize; i++)
	{
		outfile << sum[i] << endl;
	}

	delete[] list;
	delete[] sum;

}