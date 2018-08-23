#include "twiteng.h"
#include "util.h"
#include "datetime.h"
#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

  TwitEng::TwitEng()
  {

  }

  TwitEng::~TwitEng()
  {
      // must iterate through hastags to delete dynamically allocated stuff
      for (map<string, User *>::iterator it = users_.begin(); it != users_.end(); ++it)
      {
          delete it->second;
      }
  }
  /**
   * Parses the Twitter database and populates internal structures
   * @param filename of the database file
   * @return true if there is an error, false if successful
   */
  bool TwitEng::parse(char* filename)
  {
      // checks if file is able to open
     ifstream infile(filename);
     if (infile.fail())
     {
         return true;
     }

     int num;
     infile >> num;
     // getline(infile, num);
     
     // checks if first line is int
     if (infile.fail())
     {
         return true;
     }
     // looping for each line
     for (int i = 0; i <= num; i++)
     {
         string line;
         getline(infile, line);
         stringstream ss(line);
         string name;
         int count = 0; // keeps track of which use in each line
         User* firstuser = NULL;

         while (ss >> name)
         {
             if (count == 0) // if first name
             {
                 firstuser = findUser(name); // creates first user
             }
             else // adds who they are following
             {
                 User* new_user = findUser(name); // declares new user for follower
                 firstuser->addFollowing(new_user); // adds following users
                 new_user->addFollower(firstuser); // adds follower
             }
             count++;
         }
     }

     // looping through each line of the tweet feed
     string line;
     // loops while getline is true
     while (getline(infile, line))
     {
         stringstream ss(line);
         // declares the four items we are parsing for
         string t_date;
         string t_time;
         string t_user;
         string t_tweet;
        // looping through each line with spaces
        for (int space = 0; space < 4; space++)
        {
            if (space == 0) // gets first date
                ss >> t_date;
            else if (space == 1) // gets time
                ss >> t_time;
            else if (space == 2) // gets user
                ss >> t_user;
            else // gets tweet
                getline(ss, t_tweet);
                t_tweet = trim(t_tweet);
        }
        
        // debugging parsing 
        /*
        cout << "Date: " << t_date << endl;
        cout << "Time: " << t_time << endl;
        cout << "User: " << t_user << endl;
        cout << "Tweet: " << t_tweet << endl;*/

        // getting date time
        DateTime datetime_;
        string date_time = t_date + " " + t_time;
        stringstream ss1(date_time);
        ss1 >> datetime_;
        addTweet(t_user, datetime_, t_tweet);
     }
     return false;
  }

  /**
   * Allocates a tweet from its parts and adds it to internal structures
   * @param username of the user who made the tweet
   * @param timestamp of the tweet
   * @param text is the actual text of the tweet as a single string
   */
  void TwitEng::addTweet(string& username, DateTime& t_time, string& text)
  {
      // define new user
      User* curr_user = findUser(username);
      // create new tweet with customized constructor
      Tweet* tweet = new Tweet(curr_user, t_time, text);
      // add tweet for user

      curr_user->addTweet(tweet);
      set<string> hashT = tweet->hashTags(); // iterator as separate variable
      // loop through hashtag set and assigning corresponding tweet to hashtag
      for (set<string>::iterator it = hashT.begin();
            it != hashT.end(); ++it)
        {
            hashTags_[*it].insert(tweet);
        }
  }

  /**
   * Searches for tweets with the given words and strategy
   * @param words is the hashtag terms in any case without the '#'
   * @param strategy 0=AND, 1=OR
   * @return the tweets that match the search
   */
  vector<Tweet*> TwitEng::search(vector<string>& terms, int strategy)
  {
    set<Tweet* > related_tweets;
        // 0 = AND
        if (strategy == 0) // AND
        {
            string curr_hash = terms[0];
            set<Tweet* > curr_tweets = hashTags_[curr_hash]; // return set of tweets
            related_tweets = curr_tweets;
            for (set<Tweet* >::iterator it = curr_tweets.begin(); 
                    it != curr_tweets.end(); ++it)
            {
                Tweet* curr = *it;
                for (unsigned int i = 1; i < terms.size(); i++)
                {
                    set<string> hash2 = curr->hashTags();
                    if (hash2.find(terms[i]) == hash2.end()) // if term is found
                        related_tweets.erase(curr);
                }
            }
        }
        // 1 = OR
        else if (strategy == 1) // OR
        {
            for (unsigned int i = 0; i < terms.size(); i++)
            {
                string curr_term = terms[i];
                related_tweets.insert(hashTags_[curr_term].begin(), hashTags_[curr_term].end());
            }
        }
        return vector<Tweet *>(related_tweets.begin(), related_tweets.end());
  }

  /**
   * Dump feeds of each user to their own file
   */
  void TwitEng::dumpFeeds()
  {
      // looping through user map to get feed
      for (map<std::string, User *>::iterator it = users_.begin(); 
            it != users_.end(); ++it)
        {
            ofstream ofile(it->first + ".feed");
            // name of user which is key of map
            ofile << it->first << endl;
            // getting vector of user tweets which is value of map
            vector<Tweet* > user_tweets = it->second->getFeed();
            for (unsigned int i = 0; i < user_tweets.size(); i++)
            {
                ofile << *user_tweets[i] << "\n";
            }
        }
  }

  User* TwitEng::findUser(string name)
  {
      User* curr_user = NULL;
      if (users_.find(name) == users_.end())
      {
          curr_user = new User(name);
          users_.insert(make_pair(name, curr_user));
      }
      else
      {
          curr_user = users_[name];
      }
      return curr_user;
  }
