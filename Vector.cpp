#include "stdafx.h"
#include "Vector.h"

const size_t DEFAULT_CAPACITY = 32;

void mySwap(int& element1, int& element2)
{
	int temp = element1;
	element1 = element2;
	element2 = temp;
}

Vector::Vector()
{
	size = 0;
	capacity = DEFAULT_CAPACITY;
	container = new int[capacity];
}

Vector::Vector(size_t capacity, size_t size)
{
	this->size = size;
	this->capacity = capacity;
	container = new int[this->capacity];

	for (size_t i = 0; i < this->size; i++)
		container[i] = 0;
}

Vector::Vector(const Vector& otherVector)
{
	size = otherVector.size;
	capacity = otherVector.capacity;
	container = new int[capacity];

	for (size_t i = 0; i < size; i++)
		container[i] = otherVector.container[i];
}

Vector::~Vector()
{
	delete[] container;
}

void Vector::Resize(size_t newCapacity)
{
	int* newContainer = new int[newCapacity];
	for (int i = 0; i < size; i++)
		newContainer[i] = container[i];

	delete[] container;
	container = newContainer;
	capacity = newCapacity;
}

void Vector::SetAt(int value, size_t index)
{
	if (index >= size)
	{
		cout << "There is no such element in the vector! (Invalid index)";
		return;
	}

	container[index] = value;
}

int Vector::GetAt(size_t index) const
{
	if (index >= size)
	{
		cout << "There is no such element in the vector! (Invalid index)";
		return -1;  // this has to be fixed(-1 could be a valid vector element)
	}

	return container[index];
}


void Vector::PushBack(int element)
{
	if (size >= capacity)
		Resize(2 * capacity);

	container[size] = element;
	size++;
}

void Vector::InsertAt(int element, size_t index)
{
	if (index > size)
	{
		cout << "Invalid index! Index is too high..." << endl;
		return;
	}

	if (index == size || index == size - 1)
		Resize(2 * capacity);

	for (int i = size; i > index; i--)
		container[i] = container[i - 1];

	container[index] = element;
	size++;
}

void Vector::DeleteAt(size_t index)
{
	if (index >= size)
	{
		cout << "Invalid index! Index is too high..." << endl;
		return;
	}

	for (int i = index; i < size - 1; i++)
		container[i] = container[i + 1];

	//container[size-1] = 0;
	size--;

	if (size < (capacity * 0.25))
		Resize(0.5 * capacity);
}

bool Vector::IsEmpty() const
{
	return size == 0;
}

size_t Vector::Size() const
{
	return size;
}

void Vector::Sort(bool sortIncreasing)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (sortIncreasing)
			{
				if (container[j] > container[j + 1])
					mySwap(container[j], container[j + 1]);
			}
			else
			{
				if (container[j] < container[j + 1])
					mySwap(container[j], container[j + 1]);
			}
		}
	}
}

bool Vector::IsSorted() const
{
	if (size == 0)
		return false;

	for (int i = 0; i < size - 1; i++)
	{
		if (container[i] > container[i + 1])
			return false;
	}

	return true;
}
void Vector::Clear() 
{
	capacity = 0;
	size = 0;
	container = 0;
}



