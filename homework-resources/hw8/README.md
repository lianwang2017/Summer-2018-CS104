# HW8 Tests

## General

1. Copy the entire `tests` directory into your `hw6` folder.
2. Navigate into the `tests` folder in your `hw6` folder.
3. Type `make` to run tests.
4. Check the `Makefile` for the other make tests. 

## Running Tests

1. Type `make heap` in the `tests` directory to run the heap tests.
2. Type `make trending` in the `tests` directory to run the trending tests.
3. Type `make hash` in the `tests` directory to run the hash tests.
4. Type `make usrpwd` in the `tests` directory to run the user and passwords tests.
5. Type `make splay` in the `tests` directory to run the splay tests.

## Splay Tests

To run the splay tests, you need the functions:

 ```
 const Key& checkRootKey()
 {
     return BinarySearchTree<Key, Value>::mRoot->getKey();
 }

 const Value& checkValue(const Key& key)
 {
     typename BinarySearchTree<Key, Value>::iterator found = find(key);
     return found->second;
 }
 ```

In your public section of the SplayTree. Or depending on your implementation, `BinarySearchTree<Key, Value>::iterator` should be `SplayTree<Key, Value>::iterator` and checkRootKey() may need the mRoot of your SplayTree that you implemented as a variable called something else.