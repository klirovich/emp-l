#include <iostream>
#include "mystring.h"
#include "Employee.h"
#include "Department.h"
#include <iomanip>
#include <fstream>
using namespace std;

Department::Department() : Count(0), First(NULL)
{}
Department::Department(String name) : Name(name), Count(0), First(NULL)
{}
Department::~Department()
{
	EmpNode * EmpPtr = First;
	while (EmpPtr != NULL)
	{
		EmpPtr = First->Next;
		delete First;
		First = EmpPtr;
	}

}

String Department::getName()
{
	return Name;
}

int Department::EmpCount()
{
	return Count;
}
Employee Department::Find(int id)
{

	if (Count == 0)			//if list empty, return nullemp
		return NULL_EMP;

	EmpNode * EmpPtr = First; //set pointer to first in list

	while (EmpPtr != NULL)  //loop until end of list
	{
		if (EmpPtr->Emp.getIDno() == id) //if ID found
			return EmpPtr->Emp;          //return emp
		else
			EmpPtr = EmpPtr->Next; // else, continue down list
	}

	return NULL_EMP;

}
Employee Department::Find(String name)
{

	if (Count == 0)			//if list empty, return nullemp
		return NULL_EMP;

	EmpNode * EmpPtr = First; //set pointer to First in list

	while (EmpPtr != NULL)    //loops until end of list
	{
		if (EmpPtr->Emp.getLname() == name) //if name matches, return emp
			return EmpPtr->Emp;
		else
			EmpPtr = EmpPtr->Next; //else continue down list
	}

	return NULL_EMP; //if not found, return nullemp
}

void Department::setName(String name)
{
	Name = name;
}

bool Department::Insert(Employee e)
{
	EmpNode * NewEmp = new EmpNode(e);	//creates new EmpNode

	if (First == NULL)	//Checks if empty list
	{					//if empty, sets new empnode to First
		First = NewEmp;
		Count++; //increments department size before
		return true; //returning true
	}

	EmpNode * Head = First; //leading pointer set to First
	EmpNode * Tail = NULL;	//trailing pointer set to null

	while (Head != NULL) //go through end of list, checks each ID and move ptrs
	{
		if (e.getIDno() == Head->Emp.getIDno()) //if id exists return false
			return false;

		if (e.getIDno() < Head->Emp.getIDno()) //if newemp's ID < id on list
		{
			NewEmp->Next = Head; //sets NewEmp's next to leading ptr

			if (Tail == NULL) //if there was only 1 emp in list and new emp
			{				  //belong in front of it, sets newEmp as  First
				First = NewEmp;
			}
			else			 //if somewhere else in list, sets the node behind
				Tail->Next = NewEmp; //to point to newEmp

			Count++;; //increments department size before
			return true; //returning true
		}
		Tail = Head;	 //sets trailing ptr to leading
		Head = Head->Next; //moves lead up one
	}

	Tail->Next = NewEmp; //points tail to NewEmp node if newEmp is last in list

	Count++; //increments department size before
	return true; //returning true
}


bool Department::Remove(int id)
{
	//If empty list
	if (First == NULL)
		return false;

	EmpNode * Head = First;
	EmpNode * Tail = NULL;

	while (Head != NULL)	//searches for ID
	{
		if (Head->Emp.getIDno() == id)
			break;	//breaks when found
		else
		{
			Tail = Head;
			Head = Head->Next;
		}
	}

	if (Head == NULL) // if head fell off end of list
		return false; //no node to remove
		
	if (Head == First) //if node to be deleted is the fist
	{
		First = First->Next; //set First node to next node in list
		delete Head; //delete the node being pointed to by Head
	}
	else //delete from somewhere else in list
	{
		//sets Tail's next to the node Head's next is pointing to
		Tail->Next = Head->Next; 
		delete Head; //deletes node Head is pointing to
	}

	Count--;
	return true;
}

void Department::Display()
{
	EmpNode * EmpPtr = First;

	while (EmpPtr != NULL) //writes out each employee in department
	{
		EmpPtr->Emp.Write();
		cout << endl;
		EmpPtr = EmpPtr->Next;
	}
}

//prints a department report
//the setw's here are funky because of how 
//I overloaded the << operator for Strings
void Department::Report()
{
	for (int i = 0; i < 71; i++) //draws a line
		cout << "_";
	cout << endl << endl;

	//Prints department name in the top center of report
	int depLength = Name.Length();	
	int position = int(35 - ((depLength)/2));

	for (int i = 0; i < position; i++)
		cout << " ";

	cout<< Name << endl << endl;


	//Prints column titles
	cout << setw(20) << left << "Name";
	cout << setw(16) << left << "EMP. ID#";
	cout << setw(11) << left << "HRLY RATE";
	cout << setw(17) << left << "HOURS";
	cout << left << "SALARY" << endl;

	EmpNode * EmpPtr = First;

	while (EmpPtr != NULL) //writes out each employee's info in department
	{
		String name = EmpPtr->Emp.getLname();
		name.Append(", ");
		name.Append(EmpPtr->Emp.getFname());

		cout << name; // prints employee name in Last, First format

		//MacGyvered the formatting for spaces in name column
		int nameLength = (name.Length()); 
		for (int i = 0; i < (20 - nameLength); i++)
			cout << " ";

		cout << setw(8) << right << EmpPtr->Emp.getIDno();
		cout << setw(17) << right << EmpPtr->Emp.getHourlyRate();
		cout << setw(7) << right << EmpPtr->Emp.getHoursWrkd();
		cout << setw(18) << right << EmpPtr->Emp.getSalary();
		cout << endl;
		EmpPtr = EmpPtr->Next;
		
	}

	cout << left << setw(45) << "\n\nTotals:";
	cout << right << setw(9) << TotalHours();
	cout << right << setw(18) << TotalSalary();
	cout << endl;
	cout << setw(16) << left << "# OF EMPS." << right << Count << endl;

	for (int i = 0; i < 71; i++)
		cout << "_";
	cout << endl << endl;
}

float Department::TotalHours()
{
	EmpNode * EmpPtr = First;
	float total = 0;

	while (EmpPtr != NULL) //writes out each employee in department
	{
		total = total + EmpPtr->Emp.getHoursWrkd();
		EmpPtr = EmpPtr->Next;
	}

	return total;
}

float Department::TotalSalary()
{
	EmpNode * EmpPtr = First;
	float total = 0;

	while (EmpPtr != NULL) //writes out each employee in department
	{
		total = total + EmpPtr->Emp.getSalary();
		EmpPtr = EmpPtr->Next;
	}

	return total;
}

//Saves the department and all its employees to a file
bool Department::Save(String FileName)
{
	char tFileName[100];

	FileName.ToCstring(tFileName);
	ofstream toFile(tFileName, ios::binary | ios::out | ios::trunc);

	if (!toFile.is_open())
	{
		cout << "File cannot be opened." << endl;
		return false;
	}

	else
	{
		//char cName[100];
		//Name.ToCstring(cName);

		toFile << Name << '\n';
		toFile << Count << '\n';

		Employee Emp;
		EmpNode * EmpPtr = First;
		
		while (EmpPtr != NULL)
		{
			toFile.write(reinterpret_cast<char*>(&(EmpPtr->Emp)), sizeof(EmpPtr->Emp));
			toFile << "\n";
			EmpPtr = EmpPtr->Next;
		}
	}

	toFile.close();
	return true;
}

//Loads in a previously saved department.
//****THIS CRASHES when I try to load a department that was saved on a 
//****previous program run.
//****But doesn't crash when I resave the department and then load it in??
bool Department::Load(String FileName)
{
	char fFileName[100];

	FileName.ToCstring(fFileName);
	ifstream fromFile(fFileName, ios::binary | ios::in);

	if (!fromFile.is_open())
	{
		cout << "File cannot be opened." << endl;
		return false;
	}

	else
	{
		Name = "";
		Count = 0;
		EmpNode * EmpPtr = First;

		while (EmpPtr != NULL)
		{
			First = First->Next;
			delete EmpPtr;
			EmpPtr = First;
		}

		First = EmpPtr = NULL;
		
		fromFile >> Name;
		

		fromFile.ignore();
		fromFile >> Count;
		fromFile.ignore();

		int prevCount = Count;
		Count = 0;
		int empCount = 0;

		Employee emp;
		
		while (empCount < prevCount)
		{
			fromFile.read(reinterpret_cast<char*>(&emp), sizeof(emp));
			fromFile.ignore();
			Insert(emp);
			empCount++;
		}
	}

	fromFile.close();
	return true;
}