#include <iostream>
using namespace std;

#include "UnorderedArray.h"
#include "OrderedArray.h"

int main()
{
	OrderedArray<int>* m_ordered;
	UnorderedArray<int>* m_unordered;
	UnorderedArray<int>* m_unorderedTwo;
	UnorderedArray<int>* m_unorderedThree;

	m_ordered = new OrderedArray<int>(1);
	m_unordered = new UnorderedArray<int>(1);
	m_unorderedTwo = new UnorderedArray<int>(1);
	m_unorderedThree = new UnorderedArray<int>(1);

	m_ordered->push(10);
	m_ordered->push(2);
	m_ordered->push(3);
	m_ordered->push(8);

	m_unordered->push(9);
	m_unordered->push(4);
	m_unordered->push(6);
	m_unordered->push(7);

	m_ordered->print();
	cout << endl;
	m_unordered->print();

	cout << "Sorting unordered array" << endl;
	m_unordered->InsertionSort();
	m_unordered->print();

	m_unorderedTwo->push(5);
	m_unorderedTwo->push(73);
	m_unorderedTwo->push(175);
	m_unorderedTwo->push(28);

	cout << endl;
	m_unorderedTwo->print();
	m_unorderedTwo->BubbleSort();
	cout << "Bubble sorting unordered array two." << endl;
	m_unorderedTwo->print();

	m_unorderedThree->push(6);
	m_unorderedThree->push(139);
	m_unorderedThree->push(45);
	m_unorderedThree->push(2);
	cout << endl;
	m_unorderedThree->print();
	m_unorderedThree->MergeSort();
	cout << "Merge sorting unordered three." << endl;
	m_unorderedThree->print();

	bool addingToOrdered = true;
	while (addingToOrdered)
	{
		cout << endl;
		m_ordered->print();
		int temp;
		cout << "Add values." << endl;
		cout << "Value: ";
		cin >> temp;
		m_ordered->push(temp);
		m_ordered->print();
		cout << "Add another? 1 for yes, 2 for no." << endl;
		cin >> temp;
		if (temp == 2)
			addingToOrdered = false;
	}

	bool addingToUnordered = true;
	while (addingToUnordered)
	{
		m_unordered->print();
		int temp;
		cout << "Add values." << endl;
		cout << "Value: ";
		cin >> temp;
		m_ordered->push(temp);
		m_ordered->print();
		cout << "Add another? 1 for yes, 2 for no." << endl;
		cin >> temp;
		if (temp == 2)
			addingToUnordered = false;
	}


	bool found = false;
	while (!found)
	{
		cout << "Search for value." << endl;
		m_ordered->print();
		int tempVal;
		int temp;
		cout << "Input search value: ";
		cin >> tempVal;
		m_ordered->search(tempVal);
		if (m_ordered->search(tempVal) < 0)
		{
			cout << "Sorry, value not found.  Try again." << endl;
		}
		else
		{
			cout << "Your value was value " << m_ordered->search(tempVal) + 1 << " in the array.";
		}
		cout << "Find another value? (1 for yes, 2 for no): ";
		cin >> temp;
		if (temp == 2)
			found = true;
	}
}