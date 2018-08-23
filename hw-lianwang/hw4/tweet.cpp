#include <iostream>
#include <sstream>
#include "tweet.h"
#include "user.h"
#include "util.h"
using namespace std;

  /**
   * Default constructor 
   */
  Tweet::Tweet()
  {

  }

  /**
   * Constructor 
   */
  Tweet::Tweet(User* user, DateTime& time, string& text)
  {
      user_ = user;
      time_ = time;
      tweet_ = text;
      string word;
      stringstream ss(tweet_);    
      while (ss >> word)
      {
          if(word[0] =='#')
          {

            convLower(word);
            hashtags_.insert(word.substr(1));
          }
      }
  }

  /**
   * Gets the timestamp of this tweet
   *
   * @return timestamp of the tweet
   */
  DateTime const & Tweet::time() const
  {
      return time_;
  }

  /**
   * Gets the actual text of this tweet
   *
   * @return text of the tweet
   */
  string const & Tweet::text() const
  {
      return tweet_;
  }

  /**
   * Returns the hashtagged words without the '#' sign
   *
   */
  set<string> Tweet::hashTags() const
  {
      return hashtags_;
  }

  /**
   * Return true if this Tweet's timestamp is less-than other's
   *
   * @return result of less-than comparison of tweet's timestamp
   */
  bool Tweet::operator<(const Tweet& other) const
  {
      return time_ < other.time();
  }

  /**
   * Outputs the tweet to the given ostream in format:
   *   YYYY-MM-DD HH::MM::SS username tweet_text
   *
   * @return the ostream passed in as an argument
   */
  ostream& operator<<(ostream& os, const Tweet& t)
  {
      os << t.time_ << " " << (t.user_->name()) << " " << t.tweet_;
      return os;
  }

  /* Create any other public or private helper functions you deem 
     necessary */

  User* Tweet::user() const
  {
      return user_;
  }
