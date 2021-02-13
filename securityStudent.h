#pragma once
#include <string>
#include "student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent();
	SecurityStudent(string ID, string First, string Last, string Email, double Age, double* Days, Degree degree);
	
	Degree GetDegreeProgram();
	void SetDegreeProgram (Degree degree);
	void print();

	~SecurityStudent();
};
