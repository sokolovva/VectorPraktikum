#pragma once
#include <iostream>
#include "stdafx.h"
#include <string.h>
class Student
{
public:
	Student() : m_name("asd"), m_age(10) {};
	Student(char* name, int age) :m_name(name), m_age(age) {}
	/*Student(char * = "", char * = "" );
	Student(const Student&);
	Student & operator=(const Student& s);
	void PrintStudent() const;*/
	~Student();
private:
	char*  m_name;
	int m_age;
};

