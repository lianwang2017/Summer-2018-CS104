#include <string>
#include <set>
#include <list>
#include <vector>
#include "user.h"
#include "tweet.h"
#include <algorithm>
using namespace std;

/* Forward Declaration to avoid #include dependencies */
class Tweet;

  /**
   * Constructor 
   */
  User::User(std::string name)
  {
    name_ = name;
  }

  /**
   * Destructor
   */
  User::~User() {
    for (list<Tweet* >::iterator it = tweets_.begin(); it != tweets_.end(); ++it)
    {
      delete *it;
    }
  }

  /**
   * Gets the name of the user 
   * 
   * @return name of the user 
   */
  string User::name() const
  {
    return name_;
  }

  /**
   * Gets all the followers of this user  
   * 
   * @return Set of Users who follow this user
   */
  set<User*> User::followers() const
  {
    return followers_;
  }

  /**
   * Gets all the users whom this user follows  
   * 
   * @return Set of Users whom this user follows
   */
  set<User*> User::following() const
  {
    return following_;
  }

  /**
   * Gets all the tweets this user has posted
   * 
   * @return List of tweets this user has posted
   */
list<Tweet*> User::tweets() const
{
  return tweets_;
}

  /**
   * Adds a follower to this users set of followers
   * 
   * @param u User to add as a follower
   */
  void User::addFollower(User* u)
  {
      followers_.insert(u);
  }

  /**
   * Adds another user to the set whom this User follows
   * 
   * @param u User that the user will now follow
   */
  void User::addFollowing(User* u)
  {
      following_.insert(u);
  }

  /**
   * Adds the given tweet as a post from this user
   * 
   * @param t new Tweet posted by this user
   */
  void User::addTweet(Tweet* t)
  {
      tweets_.push_back(t);
  }

  /**
   * Produces the list of Tweets that represent this users feed/timeline
   *  It should contain in timestamp order all the tweets from
   *  this user and all the tweets from all the users whom this user follows
   *
   * @return vector of pointers to all the tweets from this user
   *         and those they follow in timestamp order
   */
  vector<Tweet*> User::getFeed()
  {
      vector<Tweet* > user_feed;
      // pushes back all tweets by user
      for (list<Tweet* >::iterator it = tweets_.begin();
            it != tweets_.end(); ++it)
        {
            user_feed.push_back(*it);
        }
      for (set<User* >::iterator it = following_.begin();
            it != following_.end(); ++it)
          {
              list<Tweet* > f_tweets= (*it)->tweets();
              for (list<Tweet* >::iterator it2 = f_tweets.begin();
                    it2 != f_tweets.end(); ++it2)
                {
                  user_feed.push_back(*it2);
                }
          }
      sort(user_feed.begin(), user_feed.end(), TweetComp());
      return user_feed;
  }
