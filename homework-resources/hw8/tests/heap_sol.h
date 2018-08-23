#ifndef HEAP_H
#define HEAP_H

/*
	This .h file implements an m-ary heap with a generic type T and the option
	for a comparator object to achieve a Max-Heap or a Min-Heap. The heap is implemented
	using a dynamically allocated array, and uses an amoratized resize operation to
	keep up the efficiency.
*/

#include <stdexcept>

// The starting capacity for the array. 
const int INITIAL_CAPACITY = 10;

// Class declaration. 
template <typename T, typename Comparator >
class Heap
{
	// Constructor/Destructor, and public access functions. 
	public:
  		Heap(int m, Comparator c);
  		~Heap();

	  	void push(const T& item);
	  	T const & top() const;
	  	void pop();
	  	bool empty() const;

	  	T const & get(int index) const;
	  	int size() const;
	  	int capacity() const;

	// Private data members and methods. 
 	private:
	 	int size_;
	 	int capacity_;
	 	int mAry_;
	 	T **array_;
	 	Comparator comp_;

	 	void initializeElements();
	 	void trickleUp(int index);
	 	void trickleDown(int index);
	 	bool checkParent(int index);
	 	int checkChildren(int index);
	 	void resize();
};

// The Constructor takes an int and a comparator object to define the m-Ary heap and how
// the information in the heap is stored. All of the other variables are initialized,
// and the array is itself dynamically initialized.
template <typename T, typename Comparator>
Heap<T, Comparator>::Heap(int m, Comparator c) : size_(0), capacity_(INITIAL_CAPACITY), mAry_(m), comp_(c)
{
	array_ = new T*[capacity_];
	initializeElements();
}

// Upon destruction, all of the elements in the array are deleted. 
template <typename T, typename Comparator>
Heap<T, Comparator>::~Heap()
{
	for(int i = 0; i < capacity_; ++i)
	{
		delete array_[i];
	}
	delete [] array_;
}

// A simple method that initializes the elements in the array to new T values. 
template <typename T, typename Comparator>
void Heap<T, Comparator>::initializeElements()
{
	for(int i = 0; i < capacity_; ++i)
	{
		array_[i] = new T;
	}
}

// Returns the top of the heap, which is located at the front of the array. 
template <typename T, typename Comparator>
T const & Heap<T, Comparator>::top() const
{
	if(empty())
	{
		throw std::logic_error("can't top an empty heap");
	}

	return *array_[0];
}

// Removes the top value of the array by replacing the value with the 
// value at the end of the array, and then performing a trickleDown()
// method to get the newly promoted item to its right spot. 
template <typename T, typename Comparator>
void Heap<T, Comparator>::pop()
{
	if(empty())
	{
		throw std::logic_error("can't pop an empty heap");
	}
	*array_[0] = *array_[size_ - 1];
	delete array_[size_ - 1];
	array_[size_ - 1] = new T;
	--size_;
	trickleDown(0);
}

// Checks whether or not the size of the array is 0.
template <typename T, typename Comparator>
bool Heap<T, Comparator>::empty() const
{
	return size_ == 0;
}

// Pushes a new item to the back of the array. If the array needs to be
// resized, the resize() method is called, and then the data is put
// into the array. The item is placed at the back of the array to keep
// the heap "complete" and then a trickleUp() method is used to get 
// it to the right spot. 
template <typename T, typename Comparator>
void Heap<T, Comparator>::push(const T& item)
{
	if(size_ == capacity_)
	{
		resize();
	}

	*array_[size_] = item;
	++size_;
	trickleUp(size_ - 1);
}

// A method to resize the array by copying the elements and allocating 
// a new array with double the capacity. When amoratized, this keeps the
// insertion at O(n). 
template <typename T, typename Comparator>
void Heap<T, Comparator>::resize() 
{
	capacity_ *= 2;
	T **newArray = new T*[capacity_]; 

	for(int i = 0; i < capacity_; ++i) 
	{
		if(i < size_) 
		{
		  newArray[i] = new T(*array_[i]);
		} 
		else 
		{
		  newArray[i] = new T;
		}
	}

	T **temp = array_;
	array_ = newArray;

	for(int i = 0; i < size_; ++i) 
	{
		delete temp[i];
	}
	delete [] temp;
}

// This is a recursive method to check the parent of the current
// index and move it up the heap until it gets to an appropriate position. 
// This method can be called from anywhere, but it is called on the last
// index of the array when pushing a new item to the heap so that the
// last item is always placed into the right position. 
template <typename T, typename Comparator>
void Heap<T, Comparator>::trickleUp(int index)
{
	if(index != 0 && checkParent(index))
	{
		T temp = *array_[(index + mAry_ - 1) / mAry_ - 1];
		*array_[(index + mAry_ - 1) / mAry_ - 1] = *array_[index];
		*array_[index] = temp;
		trickleUp((index + mAry_ - 1) / mAry_ - 1);
	}
}

// This is a recursive method to move an item down the heap until it is
// at its proper position. This is always started on the 0th index when 
// poping the heap, so that the newly promoted element ends up in the 
// right place. 
template <typename T, typename Comparator>
void Heap<T, Comparator>::trickleDown(int index)
{
	int childIndex = checkChildren(index);
	if(index < size_ - 1 && childIndex != -1)
	{
		T temp = *array_[childIndex];
		*array_[childIndex] = *array_[index];
		*array_[index] = temp;
		trickleDown(childIndex);
	}
}

// Checks if the item in the current index should be where the parent 
// is by using the comparator object. 
template <typename T, typename Comparator>
bool Heap<T, Comparator>::checkParent(int index)
{
	return comp_(*array_[index], *array_[(index + mAry_ - 1) / mAry_ - 1]);
}

// Checks all of the children of a parent to see if their values should be
// swapped with the parent. In order to retain the heap property, we use the
// comparator object to check all of the children, and then again to check 
// against the parent. If the item should be swapped, the index for where it
// should go is returned, otherwise the return value is -1 when the parent
// is in the right place.  
template <typename T, typename Comparator>
int Heap<T, Comparator>::checkChildren(int index)
{
	T value = *array_[index];
	T minMax;
	int minMaxIndex = mAry_ * index + 1;
	if(minMaxIndex > size_ - 1)
	{
		return -1;
	}
	else
	{
		minMax = *array_[minMaxIndex];
	}

	for(int i = minMaxIndex + 1; i <= mAry_ * (index + 1); ++i)
	{
		if(i > size_ - 1)
		{
			break;
		}

		if(comp_(*array_[i], minMax))
		{
			minMax = *array_[i];
			minMaxIndex = i;
		}
	}

	if(comp_(minMax, value))
	{
		return minMaxIndex;
	}
	else
	{
		return -1;
	}
}

// These functions have been added for testing purpouses. They are 
// all declared as const functions so they are guaranteed to never
// change the data in the Board instance. 
template <typename T, typename Comparator>
T const & Heap<T, Comparator>::get(int index) const
{
	return *array_[index];
}

template <typename T, typename Comparator>
int Heap<T, Comparator>::size() const
{
	return size_;
}

template <typename T, typename Comparator>
int Heap<T, Comparator>::capacity() const
{
	return capacity_;
}

#endif