#pragma once
template <class TYPE> class myVector
{
private:
	unsigned int size;
	unsigned int capacity;
	TYPE* myVector;
	bool empty;
	bool oneFilledIndex;

public:

	myVector()
	{
		capacity = 2;
		size = 0;
		myVector = new TYPE[capcity];
		empty = true;
		oneFilledIndex = false;
	}

	myVector(unsigned int amount, TYPE input)
	{
		
	}
	myVector()
	{

	}


	TYPE& operator [ ] (unsigned int x)
	{
		return myVector[x];
	}



};