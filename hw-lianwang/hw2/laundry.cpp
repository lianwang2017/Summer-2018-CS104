#include "stackint.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Usage ./laundry input_file output_file" << endl;
        return 1;
    }
    // checks for input file
    ifstream infile(argv[1]);
	if (infile.fail())
	{
		cout << "Error. Unable to open file: " << argv[1] << endl;
		return 1;
    }
    
    ofstream ofile(argv[2]);

    StackInt stack;
    int num = 0;
    while(infile >> num)
    {
        // 0 = black towel
        if (num == 0)
        {
            stack.push(num);
        }
        // -1 = white towel
        else if (num == -1)
        {
            stack.push(num);
        }
        // number of towels collected
        else
        {
            for (int i = 0; i < num; i++)
            {
                int towel = stack.top();
                string color;
                if (towel == 0)
                    color = "black";
                else
                    color = "white";
                ofile << color << " ";
                stack.pop();
            }
            ofile << endl;
        }
    }

    ofile.close();
}