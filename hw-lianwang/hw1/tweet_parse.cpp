#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 1)
	{
		cout << "Error. Usage: ./tweet_parse input.txt" << endl;
		return 1;
	}

	ifstream infile(argv[1]);
	if (infile.fail())
	{
		cout << "Error. Cannot open file: " << argv[1] << endl;
		return 1;
	}

	// creates vector for each line in tweet
	vector<string> temp;

	// creates vector for unique users in tweet
	vector<string> users;

	// creates vector for unique hashtags in tweet
	vector<string> hashtags;

	string line;
	while(getline(infile, line))
		{
			temp.push_back(line);
		}

	// vector of lines with no empty indexes
	vector<string> lines;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] != "")
			lines.push_back(temp[i]);
	}
	// checking for correct output of lines
	/*for(int i = 0; i < lines.size(); i++)
	{
		cout << i+1 << " " << lines[i] << endl;
	}*/

	// adds all words to word vector
	for (int i = 0; i < lines.size(); i++)
	{
		stringstream ss(lines[i]);
		string word;
		while (ss >> word)
		{
			if (word.substr(0,1) == "@")
				users.push_back(word.substr(1));
			else if (word.substr(0,1)== "#")
				hashtags.push_back(word.substr(1));
			else
				continue;
		}
	}

	// checking for all users and hashtags 
	/*for (int i = 0; i < users.size(); i++)
	{
		cout << "User " << i+1 << " : " << users[i] << endl;
	}	
	for (int i = 0; i < hashtags.size(); i++)
	{
		cout << "Hashtag " << i+1 << " : " << hashtags[i] << endl;
	} */

	// checking for unique users
	vector<string> uniqueUser;
	uniqueUser.push_back(users[0]);
	for (int i = 1; i < users.size(); i++)
	{
		bool isUnique = false;
		for (int j = 0; j < uniqueUser.size(); j++)
		{
			if (uniqueUser[j] == users[i])
			{
				isUnique = false;
				break;
			}
			else
				isUnique = true;
		}
		if (isUnique)
		{
			uniqueUser.push_back(users[i]);
		}
	}
	
	// checking for unique hashtags
	vector<string> uniqueHash;
	uniqueHash.push_back(hashtags[0]);
	for (int i = 1; i < hashtags.size(); i++)
	{
		bool isUnique = false;
		for (int j = 0; j < uniqueHash.size(); j++)
		{
			if (uniqueHash[j] == hashtags[i])
			{
				isUnique = false;
				break;
			}
			else
				isUnique = true;
		}
		if (isUnique)
		{
			uniqueHash.push_back(hashtags[i]);
		}
	}

	// checks unique users and hashtag vectors
	/*cout << "Unique Users: " << endl;
	for (int i = 0; i < uniqueUser.size(); i++)
		cout << "\t" << uniqueUser[i] << endl;

	cout << "Unique Hashtags: " << endl;
	for (int i = 0; i < uniqueHash.size(); i++)
		cout << "\t" << uniqueHash[i] << endl; */

	// prints out number of tweets, unique users and hashtags
	cout << "1. Number of tweets=" << lines.size() << endl;
	cout << "2. Unique users" << endl;
	for (int i = 0; i < uniqueUser.size(); i++)
	{
		cout << uniqueUser[i] << endl;
	}
	cout << "3. Unique hashtags" << endl;
	for (int i = 0; i < uniqueHash.size(); i++)
	{
		cout << uniqueHash[i] << endl;
	}
	return 0;
}