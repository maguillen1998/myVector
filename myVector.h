#pragma once
/*set to initialize all ints to 0*/

template <class TYPE> class vector
{
private:
	unsigned int myVectorSize;
	unsigned int myVectorCapacity;
	TYPE* myVector;
	
	
	void resizeHelper()
	{/*simplifies the application of the resize functions*/
	 /*shouldnt call downsize when capacity is 2 to keep the minimum size*/
		if (halfFull() && myVectorCapacity != 2)
		{
			downsize(myVectorCapacity / 2);
		}
		else if (full())
		{
			upsize(myVectorCapacity * 2);
		}
	}

	void upsize(unsigned int newSize)
	{/*starts copying array from "front" to "back" of origional list starting from
	 index 0 of the new list. front is set to 0, back is set to the old capacity - 1*/
		unsigned int oldCapacity = myVectorCapacity;
		myVectorCapacity = newSize;
		TYPE* newList = new TYPE[myVectorCapacity];

		for (unsigned int i = 0; i < oldCapacity; i++)
		{
			newList[i] = myVector[i];
		}

		delete[] myVector;
		myVector = newList;
	}

	void downsize(unsigned int newSize)
	{
		unsigned int oldCapacity = myVectorCapacity;
		myVectorCapacity = newSize;
		TYPE* newList = new TYPE[myVectorCapacity];

		for (unsigned int i = 0; i < myVectorCapacity; i++)
		{
			newList[i] = myVector[i];
		}

		delete[] myVector;
		myVector = newList;
	}

	bool halfFull()
	{
		if (myVectorCapacity / 2 == myVectorSize)
			return 1;
		else
			return 0;
	}

	bool full()
	{
		if (myVectorSize == myVectorCapacity)
			return 1;
		else
			return 0;
	}

	bool empty()
	{
		if (myVectorSize == 0)
			return 1;
		else
			return 0;
	}
	
	bool oneFilledIndex()
	{
		if (myVectorSize == 1)
			return 1;
		else
			return 0;
	}

public:

	vector()
	{
		myVectorCapacity = 2;
		myVectorSize = 0;
		myVector = new TYPE[myVectorCapacity];
	}

	vector(unsigned int initialSize, TYPE initialValues)
	{
		myVectorCapacity = 2;
		myVectorSize = 0;
		myVector = new TYPE[myVectorCapacity];

		for (unsigned int i = 0; i < initialSize; i++)
		{
			myVector[i] = initialValues;
			myVectorSize++;
			resizeHelper();
		}
	}

	vector(unsigned int initialSize)
	{
		myVectorCapacity = 2;
		myVectorSize = 0;
		myVector = new TYPE[myVectorCapacity];
		for (unsigned int i = 0; i < initialSize; i++)
		{
			myVectorSize++;
			resizeHelper();
		}
	}

	TYPE& operator [ ] (unsigned int x)
	{
		return myVector[x];
	}

	unsigned int size()
	{
		return myVectorSize;
	}

	unsigned int capacity()
	{
		return myVectorCapacity;
	}

	void push_back(TYPE input)
	{
		/*add input to back element of array*/
		if (!full())
		{
			myVector[myVectorSize] = input;
			myVectorSize++;
		}
		else
		{
			resizeHelper();
			push_back(input);
		}

	}

	TYPE pop_back()
	{
		/*output last element*/
		if (!empty())
		{
			TYPE output = myVector[myVectorSize - 1];
			myVectorSize--;
			resizeHelper();
			return output;
		}
		else
		{
			//do nothing
		}
	}

	void printVector()
	{
		for (unsigned int i = 0; i < size(); i++)
		{
			cout << myVector[i] << endl;
		}
	}
};