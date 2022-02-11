#include "student.h"
#include "roster.h"
#include<string>

using namespace std;

roster::~roster()
{
	cout << "***Destructor Initiated***"<< endl;
}

void roster::parse(string token) {

	// Parse studentID
	size_t rhs = token.find(",");
	string xstudentID = token.substr(0, rhs);

	//Parse firstName
	size_t lhs = rhs + 1;
	rhs = token.find(",", lhs);
	string xfirstName = token.substr(lhs, rhs - lhs);

	//Parse lastName
	lhs = rhs + 1;
	rhs = token.find(",", lhs);
	string xlastName = token.substr(lhs, rhs - lhs);

	//Parse emailAddress
	lhs = rhs + 1;
	rhs = token.find(",", lhs);
	string xemailAddress = token.substr(lhs, rhs - lhs);

	//Parse age
	lhs = rhs + 1;
	rhs = token.find(",", lhs);
	int xage = stoi(token.substr(lhs, rhs - lhs));

	//Parse numDaysToComplete *****HELP***FOR LOOP?
	lhs = rhs + 1;
	rhs = token.find(",", lhs);
	int numDaysToComplete0 = stoi(token.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = token.find(",", lhs);
	int numDaysToComplete1 = stoi(token.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = token.find(",", lhs);
	int numDaysToComplete2 = stoi(token.substr(lhs, rhs - lhs));

	//Parse degreeProgram
	lhs = rhs + 1;
	rhs = token.find(",", lhs);
	string strdegreeProgram = token.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SOFTWARE;
	if (strdegreeProgram == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}
	else if (strdegreeProgram == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	else if (strdegreeProgram == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	
	//Call to add
		add(xstudentID, xfirstName, xlastName, xemailAddress, xage, numDaysToComplete0,numDaysToComplete1,numDaysToComplete2, degree);
}

//Add Students 
void roster::add(string xstudentID, string xfirstName, string xlastName, string xemailAddress, int xage, int numDaysToComplete0, int numDaysToComplete1, int numDaysToComplete2, DegreeProgram xdegreeProgram)
{
	int classArray[] = { numDaysToComplete0 , numDaysToComplete1, numDaysToComplete2 };
	classRosterArray[index++] = new Student(xstudentID, xfirstName, xlastName, xemailAddress, xage, classArray, xdegreeProgram);
		}

//Remove Student
void roster::remove(string xstudentID)
{
	int i;
	bool present = false;
	for (i = 0; i < index; i++) {
		if (classRosterArray[i]->GetStudentID() == xstudentID) {
			present = true;
			delete classRosterArray[i];
			cout << xstudentID << " " << "has been successfully removed." << endl;
			classRosterArray[i] = classRosterArray[i + 1];
			classRosterArray[i + 1] = classRosterArray[i + 2];
			index--;
		}
		
	}
	if (present == false)
		cout << "Student" << " " << xstudentID <<" not found." << endl;
}

void roster::printinvalidEmails() {

	cout << "Invalid Emails:" << endl;
	int i;
	int atIndex;
	int dotIndex;
	int spaceIndex;
	string emailContainer;

	for (i = 0; i < 5; i++) {
		emailContainer = classRosterArray[i]->GetEmailAddress();
		atIndex = emailContainer.find('@');
		dotIndex = emailContainer.find('.');
		spaceIndex = emailContainer.find(' ');
		if (atIndex == string::npos || dotIndex==string::npos  || spaceIndex != string::npos) {
			cout << emailContainer << " is invalid."<<endl;
		}
		else { 
			//cout << emailContainer << " is an valid email. " << endl;//***test*** delete after fixed
			cout << endl;
			
			}
		}

	}

void roster::printByDegreeProgram(DegreeProgram xdegreeProgram)
{
	cout << "Displaying students enrolled in degree program: SOFTWARE:" << endl;

	int i;
	DegreeProgram degreeContainer;
	for (i = 0; i < 5; i++) {
		degreeContainer = classRosterArray[i]->GetDegreePrograms();
		if (degreeContainer == xdegreeProgram) {
			classRosterArray[i]->print();
			i++;

		}

	}
}

void roster::printAll() {
	int i;
	for (i = 0; i < index; i++) {
		classRosterArray[i]->print();
	}
}

void roster::printAverageDaysInCourse(string studentID)
{
	int TotalDays = 0;
	int i;
	for (i = 0; i < 5; i++) {

		if (classRosterArray[i]->GetStudentID() == studentID)
			TotalDays = *(classRosterArray[i]->GetNumDaysToComplete()) +
			*(classRosterArray[i]->GetNumDaysToComplete() + 1) +
			*(classRosterArray[i]->GetNumDaysToComplete() + 2);
			}
	cout << "Student ID : " << studentID << ",  ";
	cout << "Average Number of  Days in Class: " << TotalDays / 3;
	cout << endl;
}



		



























