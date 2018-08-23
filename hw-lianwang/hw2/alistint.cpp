#include "alistint.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>


/**
   * Default constructor - default to a list of capacity = 10
   */
AListInt::AListInt()
{
    cap_ = 10;
    data_ = new int[cap_];
    size_ = 0;
}

/**
   * Another constructor - default to a list to the indicated capacity
   */
AListInt::AListInt(int cap)
{
    cap_ = cap;
    data_ = new int[cap_];
    size_ = 0;
}

/**
   * Destructor
   */
AListInt::~AListInt()
 {
     delete[] data_;
 }

  /**
   * Returns the current number of items in the list 
   */
  int AListInt::size() const
  {
      return size_;
  }

  int AListInt::cap() const
  {
      return cap_;
  }
  
  /**
   * Returns true if the list is empty, false otherwise
   */
  bool AListInt::empty() const
  {
      if (size_ == 0)
      {
          return true;
      }
      else
      {
          return false;
      }
  }

  /**
   * Inserts val so it appears at index, pos
   */
  void AListInt::insert (int pos, const int& val)
  {
      // if position does not exist
      if (pos > cap_ || pos < 0)
      {
          return;
      }
      // otherwise if arr is at full cap
      else if (size_ == cap_)
      {
        resize();
        for(int i = size_; i > pos; i--)
        {
            data_[i] = data_[i-1];
        }
        data_[pos] = val;
        size_++;
      }
      // otherwise if arr is not at full cap
      else
      {
        for(int i = size_; i > pos; i--)
        {
            data_[i] = data_[i-1];
        }
        data_[pos] = val;
        size_++;
      }
  }

  /**
   * Removes the value at index, pos
   */
  void AListInt::remove (int pos)
  {
    if (pos > size_ || pos < 0)
    {
        return;
    }
    else
    {
        for (int i = pos; i < size_; i++)
        {
            data_[i] = data_[i+1];
        }
        size_--;
    }
  }

  /**
   * Overwrites the old value at index, pos, with val
   */
  void AListInt::set (int position, const int& val)
  {
      if (position > cap_ || position < 0)
      {
          return;
      }
      else
      {
          data_[position] = val;
      }
  }

  /**
   * Returns the value at index, pos
   */
  int& AListInt::get (int position)
  {
        if (position > cap_ || position < 0)
        { 
            // error
        }
        else
        {
            return data_[position];
        }   
  }

  /**
   * Returns the value at index, pos
   */
  int const & AListInt::get (int position) const
  {
        if (position > cap_ || position < 0)
        {
            // error
        }
        else
        {
            return data_[position];
        }
  }

  /**
   * Should double the size of the list maintaining its contents
   */
  void AListInt::resize()
  {
      cap_ = cap_*2;
      int* newdat = new int[cap_];
      for (int i = 0; i < size_; i++)
      {
          newdat[i] = data_[i];
      }
      data_ = newdat;
      delete[] newdat;
  }