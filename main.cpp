//Assignment 5
//Department & Employee class

#include <iostream>
#include <iomanip>
#include <fstream>
#include "mystring.h"
#include "Employee.h"
#include "Department.h"

void menu();

void main()
{
	void line();

	Employee Emp1;

	Emp1.setFname("Hermione");
	Emp1.setIDno();
	Emp1.setLname("Granger");
	Emp1.setHourlyRate(40.50f);
	Emp1.setHoursWrkd(45.3f);

	Employee Emp2("Ron", "Weasley", 35.5f, 22.3f);
	Employee Emp4("Draco", "Malfoy", 50, 44);
	Employee Emp3("Luna", "Lovegood", 20.7f, 33);

	Department Dep1("Hogwarts");

	Dep1.Insert(Emp1); //1001
	Dep1.Insert(Emp2); //1002
	Dep1.Insert(Emp3); //1004
	Dep1.Insert(Emp4); //1003

	String input;
	while (!(input == "Q"))
	{
		menu();
		cout << "Enter selection: ";
		cin >> input;
		input.ToUpper();

		if (input == "I")
		{
			Employee newEmp;
			newEmp.Read();
			Dep1.Insert(newEmp);
		}

		if (input == "F")
		{
			int empID;
			cout << "Please enter the EMPID of the employee you wish to find:";

			cin >> empID;

			if (Dep1.Find(empID) == NULL_EMP)
			{
				cout << "Can't find that employee.";
				return;
			}

			Dep1.Find(empID).Write();

			cout << endl;
		}

		if (input == "E")
		{
			Dep1.Display();
		}

		if (input == "L")
		{
			cout << "Department Name: " << Dep1.getName() << endl;
			cout << "Total Number of Employees: " << Dep1.EmpCount() << endl;
			cout << "Payroll Total: " << Dep1.TotalSalary() << endl;
			cout << "Hours Worked Total: " << Dep1.TotalHours() << endl;
		}

		if (input == "R")
		{
			int empID;
			cout << "Please enter EMPID of the employee you wish to remove:";
			cin >> empID;
			if (Dep1.Remove(empID))
				cout << "Employee removed." << endl;
		}

		if (input == "P")
			Dep1.Report();

		if (input == "X")
		{
			String filename;
			cout << "Enter the file name that you wish to save to:" << endl;
			cin >> filename;

			Dep1.Save(filename);
		}

		if (input == "Y")
		{
			String filename;
			cout << "Enter the file name that you wish to load from:" << endl;
			cin >> filename;

			Dep1.Load(filename);
		}
		
	}
}

void line()
{
	for (int i = 0; i < 16; i++)
		cout << "-";
	cout << endl;
}

void menu()
{
	cout << endl;
	cout << setw(36) << right << "Menu" << endl;

	for (int i = 0; i < 71; i++) //draws a line
		cout << "_";
	cout << endl << endl;

	

	cout << setw(5) << left << " I-";
	cout << "Insert [Add an employee to project]"<< endl;
	cout << setw(5) << left << " F-";
	cout << "Find [View an employee's data]" << endl;
	cout << setw(5) << left << " E-";
	cout << "Employee Display [Display all employee data]" << endl;
	cout << setw(5) << left << " L-";
	cout << "Summary [Display department summary]" << endl;
	cout << setw(5) << left << " R-";
	cout << "Remove [Delete an employee from project]" << endl;
	cout << setw(5) << left << " P-";
	cout << "Generate Payroll Report" << endl;
	cout << setw(5) << left << " X-";
	cout << "Save data to file" << endl;
	cout << setw(5) << left << " Y-";
	cout << "Load data from file" << endl;

	for (int i = 0; i < 71; i++) //draws a line
		cout << "_";
	cout << endl << endl;

	cout << endl;
	cout << setw(5) << left << " Q-";
	cout << "Quit [Exit program]\n" << endl;	
}

