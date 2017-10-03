#ifndef __EMPLIST_H
#define __EMPLIST_H

#include <iostream>
#include "mystring.h"
#include "Employee.h"
using namespace std;

class EmpList
{
private:
	EmpNode * head;
	int size;

public:
	EmpList() : head(NULL), size(0)
	{}

};

class EmpNode
{
private:
	Employee Emp;
	EmpNode * Next;

public:
	EmpNode() : Emp(NULL_EMP), Next(NULL)
	{}
	EmpNode(Employee e) : Emp(e), Next(NULL)
	{}
};


#endif
