#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
using namespace std;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

void Roster::parseAdd(string row)
{
	if (lastIndex < capacity) 
	{
		lastIndex++;
		double darray[Student::numberDaysSize];
		double agetoken;
		string sortNetwork = "NETWORK";
		string sortSoftware = "SOFTWARE";
		string sortSecurity = "SECURITY";
		size_t foundNetwork = row.find(sortNetwork);
		size_t foundSoftware = row.find(sortSoftware);
		size_t foundSecurity = row.find(sortSecurity);
		
		if (foundNetwork != string::npos)
		{
			this->classRosterArray[lastIndex] = new NetworkStudent(); //dynamic
			classRosterArray[lastIndex]->SetDegreeProgram(NETWORK);
		}
		else if (foundSoftware != string::npos)
		{
			this->classRosterArray[lastIndex] = new SoftwareStudent(); //dynamic
			classRosterArray[lastIndex]->SetDegreeProgram(SOFTWARE);
		}
		else if (foundSecurity != string::npos)
		{
			this->classRosterArray[lastIndex] = new SecurityStudent(); //dynamic
			classRosterArray[lastIndex]->SetDegreeProgram(SECURITY);
		}
		else
		{
			cerr << "Invalid degree program.";
			exit(-1);
		}
		
		//Student ID
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->SetStudentID(studentData[lastIndex].substr(0, rhs));

		//First Name
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->SetStudentFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Last Name
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->SetStudentLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Email
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->SetStudentEmail(studentData[lastIndex].substr(lhs, rhs - lhs));
		
		//Age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		agetoken = stod(studentData[lastIndex].substr(lhs, rhs - lhs));
		classRosterArray[lastIndex]->SetStudentAge(agetoken);

		//Days
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		darray[0] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		darray[1] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		darray[2] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

		classRosterArray[lastIndex]->SetNumberDaysComplete(darray);
	}
	else
	{
		cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY!" << endl << "EXITING NOW!";
		exit(-1);
	}
}

bool Roster::remove(string ID)
{
	bool found = false;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			if (this->classRosterArray[i]->GetStudentID() == ID)
			{
				found = true;
				delete this->classRosterArray[i];
				this->classRosterArray[i] = this->classRosterArray[lastIndex];
			}
		}
	}
	if (!found) cout << "Student not found!" << endl;
	return found;
}

void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++)
	{
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string ID)
{
	bool found = false;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			if (this->classRosterArray[i]->GetStudentID() == ID)
			{
				found = true;
				double* d = classRosterArray[i]->GetNumberDaysComplete();
				cout << ID << "'s average number of days in class is " << (d[0] + d[1] + d[2]) / 3 << endl;
			}
		}
	}
	if (!found) cout << "Student not found!" << endl;
}

//Invalid Emails
void Roster::printInvalidEmails()
{
	cout << "Displaying invalid emails:" << endl;
	for (int i = 0; i <= lastIndex; i++)
	{
		string email = classRosterArray[i]->GetStudentEmail();
		string atSym = "@";
		string fullStop = ".";
		string emptySpace = " ";
		size_t foundAt = email.find(atSym);
		size_t foundStop = email.find(fullStop);
		size_t foundSpace = email.find(emptySpace);

		if (foundAt == string::npos || foundStop == string::npos || foundSpace != string::npos)
		{
			cout << "Student ID: " << classRosterArray[i]->GetStudentID() << ": ";
			cout << " Student Email: " << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree degree)
{
	cout << "Printing degrees of type " << degreeTypeStrings[degree] << endl;
	for (int i = 0; i <= lastIndex; i++) 
	{
		if (this->classRosterArray[i]->GetDegreeProgram() == degree) this->classRosterArray[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			delete classRosterArray[i];
		}
	}
	cout << "Roster destructor called" << endl;
}

//MAIN
int main()
{
	cout << "C867 -- Scripting and Programming Applications\t" << "Made with C++" << endl;
	cout << "Student ID #000750737\t" << "Chase Wright" << endl;
	Roster* classRoster = new Roster(numberOfStudents);
	cout << "Creating new roster object." << endl;
	for (int i = 0; i < numberOfStudents; i++)
	{
		classRoster->parseAdd(studentData[i]);
	}
	cout << "Done." << endl;

	cout << "Printing all student data: " << endl;
	classRoster->print_All();

	//Print invalid emails.
	classRoster->printInvalidEmails();

	//Iterate through each student, print average days.
	cout << "Printing average days for each student ID: " << endl;
	for (int i = 0; i < 5; i++)
	{
		string ID = studentData[i].substr(0,2);
		classRoster->printAverageDaysInCourse(ID);
	}
	
	//Print list of software students.
	classRoster->printByDegreeProgram(SOFTWARE);

	cout << "Removing student A3: " << endl;
	classRoster->remove("A3");

	cout << "Removing student A3: " << endl;
	classRoster->remove("A3");

	system("pause");

	return 0;
}