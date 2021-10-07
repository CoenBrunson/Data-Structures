#pragma once
#include <cassert>

template<class T>
class Array
{

public:

	Array(int size, int growBy) : m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) {
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize); //Allocates memory (array, element, mem per element (4 bites per T element) * num of elements) - Big-O(N)

			m_growSize = ((growBy > 0) ? growBy : 0); // (if growBy larger than 0 set m_growSize to growBy as set, else set growBy & m_growSize = 0)
		}
	}

	//Destructor
	~Array()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	//Remove the last item inserted into the array - Big-O(1)
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}

	void print()
	{
		for (int k = 0; k < m_maxSize; k++)
			cout << m_array[k] << "  ";
		cout << endl;
	}

	//Remove an item with an index - Big-O(N)
	void remove(int index)
	{
		assert(m_array != NULL);
		if (index >= m_numElements)
		{
			return;
		}

		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1]; //turn current index into next value
			}
		}
		m_numElements--; //decrease num of elements by 1 after operation
	}

	//Overload [] operator
	T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}

	//Gets n sets
	int getMaxSize() { return m_maxSize; }
	int getSize() { return m_numElements; }
	int getGrowSize() { return m_growSize; }
	void setGrowSize(int growBy)
	{
		assert(growBy != 0);
		m_growSize = growBy;
	}

	//Clear method - Big-O(1)
	void clear()
	{
		m_numElements = 0; //Elements are still technically there, we're just ignoring them
	}

	//Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}

		//Create new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(m_array != NULL);

		//Copy contents of old to new
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		//Delete old array
		delete[] m_array;
		//Clean up variable assignments
		m_array = temp;
		temp = NULL;
		m_maxSize += m_growSize;
		m_growSize += m_growSize;

		return true;
	}

	void PrintNumReverse(int x)
	{
		// Base Case
		if (x <= 0)
		{
			return;
		}
		//////////////

		// The actual work this function has to do
		cout << " " << x;

		// Tail Recursion
		PrintNumReverse(x - 1);
	}

public:
	//variables, mostly style (separates functions and vars)
	T* m_array;			//pointer to array address

	int m_maxSize;		//max size of array, added later
	int m_growSize;		//amount array can grow through Expansion
	int m_numElements;	//current num of items in array
};

