#include "student.h"
#include<iostream>
#include<iomanip>;
using namespace std;


Student::Student()
{
	cout << "Please re-enter in the correct format.";
}

Student::Student(string xstudentID, string xfirstName, string xlastName, string xemailAddress, int xage, int* xnumDaysToComplete, DegreeProgram xdegreeProgram)
{
	studentID = xstudentID;
	firstName = xfirstName;
	lastName = xlastName;
	emailAddress = xemailAddress;
	age = xage;
	numDaysToComplete[0] = xnumDaysToComplete[0];
	numDaysToComplete[1] = xnumDaysToComplete[1];
	numDaysToComplete[2] = xnumDaysToComplete[2];
	degreeProgram = xdegreeProgram;
}

void Student::SetStudentID(string xstudentID) {
	studentID = xstudentID;
}
void Student::SetStudentFirstName(string xfirstName) {
	firstName = xfirstName;
}
void Student::SetStudentLastName(string xlastName) {
	lastName = xlastName;
}
void Student::SetEmailAddress(string xemailAddress) {
	emailAddress = xemailAddress;
}
void Student::SetAge(int xage) {
	age = xage;
}
void Student::SetNumDaysToComplete(int* xnumDaysToComplete) {
	numDaysToComplete[0] = xnumDaysToComplete[0];
	numDaysToComplete[1] = xnumDaysToComplete[1];
	numDaysToComplete[2] = xnumDaysToComplete[2];
}

void Student::SetDegreePrograms(DegreeProgram xdegreeProgram) {
	degreeProgram = xdegreeProgram;
}

string Student::GetStudentID() const
{
	return studentID;
}

string Student::GetStudentFirstName() const
{
	return firstName;
}

string Student::GetStudentLastName() const
{
	return lastName;
}

string Student::GetEmailAddress() const
{
	return emailAddress;
}

int Student::GetAge() const
{
	return age;
}

DegreeProgram Student::GetDegreePrograms() const
{
	return degreeProgram;
}
void Student::print()
{
	cout << left << setw(3) <<studentID;
	cout << left << setw(10) << firstName;
	cout << left << setw(15) << lastName;
	cout << left << setw(25) << emailAddress;
	cout << left<< setw(10) << age;
	cout << "\t" << "{"<<numDaysToComplete[0];
	cout << "\t" << numDaysToComplete[1];
	cout << "\t" << numDaysToComplete[2]<< "}";
	if (degreeProgram == 0) 
		cout << "\t" << "SECURITY" << endl;
	if (degreeProgram == 1)
		cout << "\t" << "NETWORK" << endl;
	if (degreeProgram == 2)
		cout << "\t" << "SOFTWARE" << endl;

}
int* Student::GetNumDaysToComplete() {
	return numDaysToComplete;
}

