#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

Student::Student()
{
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmail = "";
	this->studentAge = 0;
	this->numberDaysComplete = new double[numberDaysSize];
	for (int i = 0; i < numberDaysSize; i++)
	{
		numberDaysComplete[i] = 0; // Dynamic allocation. https://tinyurl.com/cnul97
	}
}

Student::Student(string ID, string First, string Last, string Email, double Age, double Days[], Degree degree)
{
	this->studentID = ID;
	this->studentFirstName = First;
	this->studentLastName = Last;
	this->studentEmail = Email;
	this->studentAge = Age;
	this->numberDaysComplete = new double[numberDaysSize];
	for (int i = 0; i < numberDaysSize; i++)
	{
		numberDaysComplete[i] = Days[i]; // Dynamic allocation. https://tinyurl.com/cnul97
	}
}

string Student::GetStudentID()
{
	return studentID;
}

string Student::GetStudentFirstName()
{
	return studentFirstName;
}

string Student::GetStudentLastName()
{
	return studentLastName;
}

string Student::GetStudentEmail()
{
	return studentEmail;
}

double Student::GetStudentAge()
{
	return studentAge;
}

double * Student::GetNumberDaysComplete()
{
	return numberDaysComplete;
}

void Student::SetStudentID(string ID)
{
	studentID = ID;
}

void Student::SetStudentFirstName(string First)
{
	studentFirstName = First;
}

void Student::SetStudentLastName(string Last)
{
	studentLastName = Last;
}

void Student::SetStudentEmail(string Email)
{
	studentEmail = Email;
}

void Student::SetStudentAge(double Age)
{
	studentAge = Age;
}

void Student::SetNumberDaysComplete(double Days[])
{
	if (this->numberDaysComplete != nullptr)
	{
		delete[] this->numberDaysComplete;
		this->numberDaysComplete = nullptr;
	}
	this->numberDaysComplete = new double[numberDaysSize];
	for (int i = 0; i < 3; i++)
	{
		this->numberDaysComplete[i] = Days[i];
	}
}

void Student::print()
{
	cout << studentID << "\t";
	cout << "First Name: " << studentFirstName << "\t";
	cout << "Last Name: " << studentLastName << "\t";
	cout << "Age: " << studentAge << "\t";
	cout << "Days in Course: ";
	cout << numberDaysComplete[0] << " ";
	cout << numberDaysComplete[1] << " ";
	cout << numberDaysComplete[2] << "\t";
	cout << "Degree Program: ";
}

Student::~Student()
{
	cout << "Student destructor called." << endl;
}