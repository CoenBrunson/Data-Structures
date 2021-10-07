#pragma once
#include <cassert>
#include "Array.h"

template <class T>
class OrderedArray : public Array<T>
{
public:
	//Constructor
	OrderedArray(int size, int growBy = 1) : Array<T>(size, growBy) {
	}

	void push(T val)
	{
		assert(this->m_array != NULL); //Debug

		if (this->m_numElements >= this->m_maxSize)
		{
			this->Expand();
		}

		int i, k;
		// Step 1: Find the index to insert val
		for (i = 0; i < this->m_numElements; i++)
		{
			if (this->m_array[i] > val)
			{
				break;
			}
		}

		assert(this->m_array[i - 1] != val);

		// Step 2: Shift everything to the right of the index forward by one
		for (k = this->m_numElements; k > i; k--)	// Moving backwards through the array starting at m_numElements
		{
			this->m_array[k] = this->m_array[k - 1];
		}

		//now my array has space for a new val
		this->m_array[i] = val;
		this->m_numElements++;
	}

	int search(T searchKey)
	{
		// Call to the binarySearch recursive function
		// Binary Search: searchkey, initial lowerbound, initial upperbound
		return binarySearch(searchKey, 0, this->m_numElements - 1);
	}

private:

	// Recursive Binary Search
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(this->m_array != NULL);
		assert(lowerBound >= 0);
		assert(upperBound < this->m_numElements);

		// Bitwise divide by 2
		int current = (lowerBound + upperBound) >> 1;	// 2^1 == >> 1

		// Did we find the searchKey at current
		if (this->m_array[current] == searchKey)
		{
			// We have found the searchKey in the array. Return the index
			return current;
		}
		// Are we done searching?
		else if (lowerBound > upperBound)
		{
			// Did not find searchKey within m_array
			return -1;
		}
		// Which half is searchKey in?
		else
		{
			if (this->m_array[current] < searchKey)
			{
				// Search the upper half of the array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				// Search the lower half of the array
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}

		return -1;
	}
};