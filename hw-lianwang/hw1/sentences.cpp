#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void readWords(char* filename, vector<vector<string> >& words);
// client interface

void generateSentences(vector<vector<string> >& words, ofstream& ofile);
// recursive helper function

void genHelper(vector<vector<string> >& words,
	       ofstream& ofile,
	       int currentOption,
	       string sentence,
	       int& numSentences);

void readWords(char* filename,vector<vector<string> >& words)
{
    ifstream infile(filename);
    string line;
    vector<string> temp;
    while(getline(infile, line))
    {
        string word;
        stringstream ss(line);
        while (ss >> word)
        {
          temp.push_back(word);
        }
        if (temp.size() != 0)
        {
          words.push_back(temp);
        }
        temp.clear();
    }
}

void generateSentences(vector<vector<string> >& words, ofstream& ofile)
{
  int num = 0;
  genHelper(words, ofile, 1, "The", num);
  genHelper(words, ofile, 0, "The", num);
  ofile << num;
}

void genHelper(vector<vector<string> >& words,
	       ofstream& ofile,
	       int currentOption,
	       string sentence,
	       int& numSentences)
{
  // in adverb vector
  if (currentOption == 4) // final base case
  {
    sentence = sentence + ".";
    //cout << sentence << endl;
    ofile << sentence << endl;
    numSentences++;
    return;
  }
  if (currentOption == 3) // base case
  {
    // couts the sentence with no adverb
    genHelper(words, ofile, ++currentOption, sentence, numSentences);
    // couts the sentence with adverb
    currentOption--;
    for (int i = 0; i < words[currentOption].size(); i++)
    {
      string add = words[currentOption][i];
      genHelper(words, ofile, ++currentOption, sentence + " " + add,
        numSentences);
      currentOption--;
    }
  }
  else
  {
    for (int i = 0; i < words[currentOption].size(); i++)
    {
      string add = words[currentOption][i];
      genHelper(words, ofile, ++currentOption, sentence + " " + add,
        numSentences);
      currentOption--;
    }
  }
}

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Usage ./sentences input_file output_file" << endl;
    return 1;
  }
  vector<vector<string> > words;

  // Parse the file
  readWords(argv[1], words);

  // checking that words vector prints correctly
  /*for (int i = 0; i < words.size(); i++)
  {
      for (int j = 0; j < words[i].size(); j++)
      {
        cout << words[i][j] << " ";
      }
      cout << endl;
  }*/


  // Check the status of parsing
  if(words.size() < 4){
    cerr << "Input file requires 4 lines of words" << endl;
    return 1;
  }

  // Open the output file
  ofstream ofile(argv[2]);
 
  // generate all the sentence options writing them to ofile
  generateSentences(words, ofile);

  ofile.close();

  return 0;
}
