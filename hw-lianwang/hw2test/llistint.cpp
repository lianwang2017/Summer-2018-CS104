#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
// note to self: loc = index in list
void LListInt::insert(int loc, const int& val)
{
  // for empty list
  if (size() == 0)
  {
    Item* temp = new Item; // creates new item to store
    temp->val = val; // sets temp value to val
    temp->prev = NULL; // prev points to null
    temp->next = NULL; // next points to null
    head_ = temp; // head points to temp
    tail_ = temp; // tail points to temp
    size_++; // increments size
  }
  // for inserting at front
  else if (loc == 0)
  {
    Item* temp = new Item; // new item to store temp
    Item* ohead = getNodeAt(0); // item to store first item
    temp->val = val; // sets value of temp to val
    temp->next = getNodeAt(0); // sets temp next to first item
    temp->prev = NULL; // set temp prev to null
    ohead->prev = temp; // set prev first item prev to temp
    head_ = temp; // head points at temp (new head)
    size_++; // increments size
  }
  // for intserting at back
  else if (loc == size())
  {
    Item* temp = new Item; // new temp item to store temp
    Item* otail = getNodeAt(loc-1); // item to store last item
    temp->val = val; // sets temp value to val
    temp->next = NULL; // sets temp next to null
    temp->prev = otail; // sets temp prev to orig tail
    otail->next = temp; // sets prev tail next to temp
    tail_ = temp; // tail points to temp (new tail)
    size_++; // increments size
  }
  // for intserting in middle
  else
  {
    Item* temp = new Item; // new temp item for new item
    Item* before = getNodeAt(loc-1); // prev item
    Item* after = getNodeAt(loc); // next item
    temp->val = val; // sets temp value to val
    temp->prev = before; // sets temp prev to item ahead
    temp->next = after; // sets temp next to current item at loc
    before->next = temp; // sets before item next to temp
    after->prev = temp; // sets after prev to temp
    size_++; // increments size
  }
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  Item* curr = getNodeAt(loc); // new item
  // if there is only one item in the list
  if (size() == 1 && loc >= 0)
  {
    head_ = NULL; // empties list
    tail_ = NULL; // empties list
    delete curr; // deletes item at location loc
    size_--; // decreases size
  }
  // removing item from front of list
  else if (loc == 0 && size() > 1)
  {
    Item* after = getNodeAt(loc+1); // item after loc
    head_ = after; // head points at next item in list (new head)
    after->prev = NULL; // next item prev points to nothing
    delete curr; // deletes current item
    size_--; // decreases size 
  }
  // removing item from end of list
  else if (loc == size()-1 && size() > 1)
  {
    Item* before = getNodeAt(loc-1); // item before loc
    tail_ = before; // tail points to new tail before
    before->next = NULL; // before next points to null
    delete curr; // deletes current item
    size_--; // decreases size
  }
  // removing item from middle of list
  else
  {
    Item* before = getNodeAt(loc-1); // prev item
    Item* after = getNodeAt(loc+1); // next item
    before->next = after; // set before item next to after
    after->prev = before; // set next item prev to before
    delete curr; // deletes current item
    size_--; // decreases size 
  }
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}
