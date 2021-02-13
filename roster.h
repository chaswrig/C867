#pragma once
#include <string>
#include <iostream>
#include "student.h"
using namespace std;

//Student Data Table
const string studentData[] =
{
 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Chase,Wright,cwri153@wgu.edu,29,20,30,40,SOFTWARE"
};

const int numberOfStudents = 5;

//E. Create Roster class
class Roster
{
public: 
	int lastIndex;
	int capacity;

	//E1 -- Create an array of pointers
	Student** classRosterArray;
	Roster();
	Roster(int capacity);

	//E2.a -- Parse the strings for data
	void parseAdd(string row);

	//E3.b -- remove student from roster, if not present, output error
	bool remove(string ID);
	
	//E3.c -- print complete tab list using loop, call for each student
	void print_All();

	//E3.d -- print average days
	void printAverageDaysInCourse(string ID);

	//E3.e -- print invalid emails
	//Valid email has '@', a '.', and no spaces 
	void printInvalidEmails();

	//E3.f -- print out student info for a degree program
	void printByDegreeProgram(Degree degree);

	//F5 -- Destructor
	~Roster();
};