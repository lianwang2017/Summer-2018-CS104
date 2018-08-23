#include <string>
#include "setstr.h"

#include <iostream>

using namespace std;

  SetStr::SetStr() {

  }

  /**
   * Destructor
   */
  SetStr::~SetStr() {

  }

  /**
   * Returns the current number of items in the list 
   */
  int SetStr::size() const
  {
        return list_.size();
  }

  /**
   * Returns true if the list is empty, false otherwise
   */
  bool SetStr::empty() const
  {
        return list_.empty();
  }

  /**
   * Inserts val into the set, do nothing if val already exists
   */
  void SetStr::insert(const std::string& val)
  {
        // check if val exists
        int i = 0; bool dne = true;
        while (dne && i < list_.size())
        {
            // set dne to false if found same val
            if (exists(val))
                dne = false;
            else
                i++;
        }
        // if val exists then exit
        if (dne == false)
            return;
        // insert if val does not exist
        list_.push_back(val);
  }

  /**
   * Removes the value from the set, do nothing if it doesn't exist
   */
  void SetStr::remove(const std::string& val)
  {
      int i = 0;
      // looping through list
      while (i < list_.size())
      {
            // if value is found
            if (list_.get(i) == val)
            {
                list_.remove(i); // removes for matches
                break;
            }
            // if value does not match
            else
                i++;
      }
      return;
  }

  std::string SetStr::get(const int i)
  {
      return list_.get(i);
  }
  /**
   * Returns true if the item is in the set
   */
  bool SetStr::exists(const std::string& val) const
  {
      int i = 0;
      while (i < list_.size())
      {
          if (list_.get(i) == val)
              return true;
          else
            i++;
      }
      return false;
  }

  /**
   * Return a pointer to the first item
   *  and support future calls to next()
   */
  std::string const* SetStr::first()
  {
        if (!list_.empty())
        {
            snext = 1;
            return &list_.get(0);
        }
        else
            return NULL;
  }

  /**
   * Return a pointer to the next item
   *  after the previous call to next
   *  and NULL if you reach the end
   */
  std::string const* SetStr::next()
  {
        if (list_.size() >= 2 && snext <= list_.size())
        {
            snext++;
            return &list_.get(snext-1);
        }
        else
        {
            cout << "asdas" << endl;
            return NULL;
        }
  }

  /**
   * Returns another (new) set that contains
   * the union of this set and "other"
   */
  SetStr SetStr::setUnion(const SetStr& other) const
  {


        SetStr new_set;
        int i = 0;
        while (i < list_.size())
        {
            new_set.insert(list_.get(i));
            i++;
        }        
        int j = 0;
        while (j < other.size())
        {
            new_set.insert(other.list_.get(j));
            j++;
        }
        return new_set;
  }

  /**
   * Returns another (new) set that contains
   * the intersection of this set and "other"
   */
  SetStr SetStr::setIntersection(const SetStr& other) const
  {
    SetStr new_set;
    int i = 0;
    while (i < this->size())
    {
        string str1 = list_.get(i);
        if (this->exists(str1) && other.exists(str1))
            new_set.insert(str1);
        i++;
    }
    return new_set;
}

// union
  SetStr SetStr::operator|(const SetStr& other) const
  {
    return setUnion(other);
  }

  // intersection
  SetStr SetStr::operator&(const SetStr& other) const
  {
    return setIntersection(other);
  }
