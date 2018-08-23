// TODO(1): Template LList class, as well as all the functions inside it
// Change appropriate mentions of int to the templated typename
class LList {

private:
  // TODO(2): What needs to happen in Item?
  struct Item {
    Item(const int& v, Item* p, Item* n);
    int val;
    Item *prev;
    Item *next;
  };

public:
  // TODO(2): What needs to happen in iterator?
  class iterator {
    friend LList;
  public:
    iterator();
    iterator& operator++();
    iterator& operator--();
    int& operator*();
    int* operator->();
    bool operator==(iterator other);
    bool operator!=(iterator other);
  private:
    iterator(Item* item);
    Item* mItem;
  };

  LList();
  LList(const LList& other);
  LList& operator=(const LList& other);
  ~LList();

  // TODO(3): Change the signatures of these methods appropriately
  int size() const;
  bool empty() const;
  void push_back(const int& val);
  int& get(int pos);
  const int& get(int pos) const;
  void clear();

  iterator begin();
  iterator end();

private:
  Item* getNodeAt(int pos) const;

  Item* mHead;
  Item* mTail;
  int mSize;
};

// TODO(4): Copy the contents of llist.cpp here and fix their signature

// TODO(5): Copy the content of iterator.h here
