
#include <iostream>
#include "stdafx.h"
#include "Vector.h"
#include "Student.h"


int main()
{
	Vector <Student>students;

	Vector vector;
	vector.PushBack(5);
	vector.PushBack(3);
	vector.PushBack(1);
	vector.PushBack(8);

	cout << "Is empty: " << vector.IsEmpty() << endl;
	cout << "Size: " << vector.Size() << endl;
	cout << "Vector elements: ";
	for (int i = 0; i < vector.Size(); i++)
		cout << vector.GetAt(i) << ", ";

	cout << endl;
	vector.Sort();
	cout << "Increasing vector: ";
	for (int i = 0; i < vector.Size(); i++)
		cout << vector.GetAt(i) << ", ";

	cout << endl;
	cout << "Is sorted: " << vector.IsSorted() << endl;

	vector.Sort(false);
	cout << "Decreasing vector: ";
	for (int i = 0; i < vector.Size(); i++)
		cout << vector.GetAt(i) << ", ";

	cout << endl;
	cout << "Is sorted: " << vector.IsSorted() << endl;

    return 0;
}

