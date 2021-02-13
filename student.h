#pragma once
#include "degree.h"
#include <string>
using namespace std;

class Student //D1. Create base Student
{
protected:
	string studentID;
	string studentFirstName;
	string studentLastName;
	string studentEmail;
	double studentAge;
	double* numberDaysComplete = NULL; //Allocate w/new. https://tinyurl.com/cnul97
	Degree degreeProgram;

public:
	//D2.a -- Getters
	const static int numberDaysSize = 3; //Needed to allocate dynamic array. https://tinyurl.com/cnul97
	string GetStudentID();
	string GetStudentFirstName();
	string GetStudentLastName();
	string GetStudentEmail();
	double GetStudentAge();
	double* GetNumberDaysComplete(); //This is a pointer because the data is a pointer.
	virtual Degree GetDegreeProgram() = 0; // D2.f -- virtual GetDegreeProgram

	//D2.b -- Setters
	void SetStudentID(string ID);
	void SetStudentFirstName(string First);
	void SetStudentLastName(string Last);
	void SetStudentEmail(string Email);
	void SetStudentAge(double Age);
	void SetNumberDaysComplete(double Days[]);
	virtual void SetDegreeProgram(Degree degree) = 0; // D2.f -- virtual SetDegreeProgram
	virtual void print() = 0; // D2.d -- virtual print()

	Student(); //Empty Constructor and D2.c -- constructor using all parameters
	Student(string ID, string First, string Last, string Email, double Age, double Days[], Degree degree);

	~Student(); // D2.e -- Destructor
};