#include "setstr.h"
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

string trimName(string name);

// trims off the white space
string trimName(string name)
{
    string newName = name;
    int i = name.size()-1;
    while (name[i])
    {
        char c = name[i];
        if (!isspace(c))
            break;
        else
        {
            newName = name.substr(0, i);
            i--;
        } 
    }
    return newName;
}
int main(int argc, char* argv[])
{
	// checks for correct number of arguments
	if (argc < 4)
	{
		cout << "Error. Usage: ./majors infile.in cmdfile.cmd outfile.out" << endl;
		return 1;
	}

	// checks for first input file majors.in
	ifstream infile(argv[1]);
	if (infile.fail())
	{
		cout << "Error. Unable to open file: " << argv[1] << endl;
		return 1;
    }

    // map(key = major, value = set of teachers)
    map<string, SetStr> majormap;
    string line;
    // looping for each line for first file 
    while(getline(infile, line))
    {
        // stringstream for parsing each line
        stringstream ss(line);
        string prof;
        // get the string for professor name
        getline(ss, prof, ',');
        // trims off whitespace
        string profname = trimName(prof);
        string majorsl;
        // get the string for all majors
        getline(ss, majorsl, '\n');
        // stringstream for parsing through majors
        stringstream ss1(majorsl);
        string major;
        while (ss1 >> major)
        {
            string nmajor = "";
            for (unsigned int i = 0; i < major.size(); i++)
            {
                char c = major[i];
                nmajor += toupper(c);
            }
            // checking if major/key already exists
            if (majormap.find(nmajor) != majormap.end())
            {
                majormap[nmajor].insert(profname);
            }
            // else major does not exist yet
            else
            {
                // creates a set string of professors for major
                SetStr profs;
                profs.insert(profname);
                majormap.insert(make_pair(nmajor, profs));
            }
        }
    }

    // checks for second input file majors.cmd
	ifstream ifile(argv[2]);
	if (ifile.fail())
	{
		cout << "Error. Unable to open file: " << argv[2] << endl;
		return 1;
    }  
    
    // creates output file
    ofstream ofile(argv[3]);
    // line for majors to search for
    string mline;
    while (getline(ifile, mline))
    {
        // turns each major into uppercase
        string major = "";
        for (unsigned int i = 0; i < mline.size(); i++)
        {
            char c = mline[i];
            major += toupper(c);
        }
        major = trimName(major);

        // to find major in map
        // with get function
        cout << "Major: " << major << ' ';
        // checks if major exists (single major)
        if(majormap.find(major) != majormap.end()) 
        {
            ofile << major << endl;
            SetStr foundProfs = majormap[major];

            ofile << *(foundProfs.first()) << endl;

            for(int i = 1; i < foundProfs.size();i++) {
                const string* nextmajor = foundProfs.next();
                ofile << *nextmajor << endl;                
            }
            // string * nextmajor = foundProfs.next();
            // cout << *nextmajor << ", ";

            ofile << endl;
        }
        // if major does not exist or double major
        else
        {
            stringstream ss2(major);
            string smajor;
            ss2 >> smajor;
            if(majormap.find(smajor) != majormap.end())
            {
                SetStr foundProf = majormap[smajor];
                while (ss2 >> smajor)
                {
                    if(majormap.find(smajor) != majormap.end()) 
                    {
                        SetStr foundProf1 = majormap[smajor];
                        foundProf = foundProf.setIntersection(foundProf1);
                    }
                }

                ofile << major << endl;
                ofile << *(foundProf.first()) << endl;
                
                for(int i = 1; i < foundProf.size();i++) 
                {
                    const string* nextmajor = foundProf.next();
                    ofile << *nextmajor << endl;                
                }
                // string * nextmajor = foundProfs.next();
                // cout << *nextmajor << ", ";
                
                ofile << endl;
            }
            else
                ofile << endl;
        }
        // cout << *(majormap[major].first());
    }
}