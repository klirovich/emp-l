#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include <iostream>
#include "Employee.h"
#include "mystring.h"
using namespace std;

class EmpNode
{
private:
	Employee Emp;
	EmpNode * Next;

public:
	EmpNode() : Next(NULL)
	{}
	EmpNode(Employee e) : Emp(e), Next(NULL)
	{}

	friend class Department;
};

class Department
{
private:
	String Name;
	int Count;
	EmpNode * First;

public:
	//constructors & destructor
	Department();
	Department(String name);
	~Department();

	//accessors
	String getName();
	Employee Find(int id);
	Employee Find(String name);
	int EmpCount();

	//modifiers
	void setName(String name);
	bool Insert(Employee e);
	bool Remove(int id);

	//output
	void Display();
	void Report();
	float TotalHours();
	float TotalSalary();

	//Save/Read//
	bool Save(String FileName);
	bool Load(String FileName);
};

#endif