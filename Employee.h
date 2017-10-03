#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include "mystring.h"
using namespace std;

class Employee
{
private:
	int idNum;
	String fName;
	String lName;
	float hRate;
	float hWorked;

	static int idCount;	//used to assign id. Incremented with assignment


public:
	//constructors//
	Employee();
	Employee(String fname, String lname, float hrte, float hwrkd);

	//accessors//
	String getFname();				//gets employee first name
	String getLname();				//gets employee last name
	String getName();				//gets employee full name
	int getIDno();					//gets employee ID number
	float getHourlyRate();			//gets employee hourly rate
	float getHoursWrkd();			//gets hours worked by employee
	float getSalary();				//gets employee salary
	bool operator == (Employee emp);//compare two employees

	//mutators//
	void setFname(String fn);		//set employee first name
	void setLname(String ln);		//set employee last name
	void setIDno();					//generate ID number
	void setIDno(int id);			//set ID number manually
	void setHourlyRate(float hr);	//set hourly rate
	void setHoursWrkd(float hw);	//set hours worked
	
	//read/write//
	void Read();					//ask for input about an employee 
	void Write();					//outputs employee info

};

extern const Employee NULL_EMP;

#endif