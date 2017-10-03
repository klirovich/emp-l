#include <iostream>
#include "mystring.h"
#include "Employee.h"
#include <iomanip>

using namespace std;

int Employee::idCount = 1001;

//Constructors//
Employee::Employee(): idNum(0), hRate(0), hWorked(0)
{}
Employee::Employee(String fname, String lname, float hrte, float hwrkd): 
fName(fname), lName(lname), hRate(hrte), hWorked(hwrkd) 
{												//initializes & generates ID
	setIDno();
}

//Accessors
String Employee::getFname()
{
	return fName;
}
String Employee::getLname()
{
	return lName;
}
String Employee::getName(){

	String fullName = fName;	//sets full name to first name
	fullName.Append(" ");		//appends space
	fullName.Append(lName);		//appends last name

	return fullName;			//Returns full name
}
int Employee::getIDno()
{
	return idNum;
}
float Employee::getHourlyRate()
{
	return hRate;
}
float Employee::getHoursWrkd()
{
	return hWorked;
}
float Employee::getSalary()
{
	float salary;				

	if (hWorked <= 40)						//no overtime
		salary = hWorked * hRate;
	else									//with overtime
	{
		float overTime = (hWorked - 40);	
		salary = float(40 * hRate) + float(overTime * (1.5 * hRate));
	}						//cast to float to make the compiler stop yelling

	return salary;
}

bool Employee::operator == (Employee emp)
{
	if ((fName == emp.fName) &&
		(lName == emp.lName) &&
		(idNum == emp.idNum) &&
		(hRate == emp.hRate) &&
		(hWorked == emp.hWorked))
		return true;

	return false;
}

//Mutators
void Employee::setFname(String fn)
{
	fName = fn;
}
void Employee::setLname(String ln)
{
	lName = ln;
}
void Employee::setIDno()
{
	idNum = idCount++;
}
void Employee::setIDno(int id){
	idNum = id;
}
void Employee::setHourlyRate(float hr)
{
	hRate = hr;
}
void Employee::setHoursWrkd(float hw)
{
	hWorked = hw;
}

//Read/Write//
void Employee::Read()
{
	String IDq;

	cout << "Enter employee first name: ";
	cin >> fName;
	cout << "Enter employee last name: ";
	cin >> lName;
	cout << "Enter employee hourly rate: ";
	cin >> hRate;
	cout << "Enter employee hours worked: ";
	cin >> hWorked;
	cout << "Manually set employee ID? [yes/no] ";
	cin >> IDq;

	IDq.ToLower();

	if (IDq == "yes")
	{
		cout << "Enter ID: ";
		cin >> idNum;
	}
	else
		setIDno();

	cout << "Employee added." << endl;

}
void Employee::Write()
{
	cout << "Employee ID number: " << idNum << endl;
	cout << "Employee name: " << getName() << endl;
	cout << "Employee hours worked: "
		<< fixed << setprecision(1) << hWorked << endl;
	cout << "Employee hourly rate: " << "$" 
		<< setprecision(2) << hRate << endl;
	cout << "Employee current salary: " << "$" 
		<< getSalary() << endl;

}

extern const Employee NULL_EMP = Employee(); //NULL_EMP object 