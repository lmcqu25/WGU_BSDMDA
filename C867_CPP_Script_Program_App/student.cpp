/* Rubric D. For the Student class, do the following:
   Create the class Student in the files student.h and student.cpp */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

#include "degree.h"
#include "student.h"

/* Rubric D2a. Getter/accessor for each instance variable from student.h in part D1. */
string student::getStudentID() const {
	return studentID;
}
string student::getFirstName() const {
	return firstName;
}
string student::getLastName() const {
	return lastName;
}
string student::getEmailAddress() const {
	return email;
}
int student::getAge() const {
	return age;
}
degreeProgramEnum student::getDegreeProgram() const {
	return degreeProgram;
}
vector<int> student::getdaysToComplete() const {
	return daysToComplete;
}

/* Rubric D2b. Setter/mutator for each instance variable from student.h in part D1 */
void student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void student::setLastName(string lastName) {
	this->lastName = lastName;
}
void student::setEmailAddress(string email) {
	this->email = email;
}
void student::setAge(int age) {
	this->age = age;
}
void student::setDegreeProgram(degreeProgramEnum degreeProgram) {
	this->degreeProgram = degreeProgram;
}
void student::setdaysToComplete(vector<int> daysToComplete) {
	this->daysToComplete = daysToComplete;
}

student::student(
	string StudentID,
	string firstName,
	string lastName,
	string email,
	int age,
	vector<int> daysToComplete,
	degreeProgramEnum degreeProgram) {
	this->studentID = StudentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->degreeProgram = degreeProgram;
	this->daysToComplete = daysToComplete;

	return;
}

/* Rubric D2e. Printing specific student data to console. */
void student::print(printItemEnum printItem) const {

	switch (printItem) {
	case printItemEnum::STUDENTID:
		cout << "StudentID: " << studentID << "\n";
		break;
	case printItemEnum::FIRSTNAME:
		cout << "First Name: " << firstName << "\n";
		break;
	case printItemEnum::LASTNAME:
		cout << "Last Name: " << lastName << "\n";
		break;
	case printItemEnum::EMAIL:
		cout << "Email: " << email << "\n";
		break;
	case printItemEnum::AGE:
		cout << "Age: " << age << "\n";
		break;
	case printItemEnum::DAYSTOCOMPLETE:
		cout << "Days In Course: ";
		cout << "{ ";
		for (size_t i = 0; i < daysToComplete.size(); i++)
		{
			cout << daysToComplete.at(i);
			if (daysToComplete.size() > i + 1) {
				cout << ", ";
			}
		}
		cout << " }";
		break;
	case printItemEnum::DEGREEPROGRAM:
		cout << "Program: " << degreeProgramStrings[(int)degreeProgram] << "\n";
		break;
	case printItemEnum::ALL:
		cout << setw(8) << "StudentID : " << setw(6) << left << studentID;
		cout << setw(8) << "First Name: " << setw(10) << firstName;
		cout << setw(8) << "Last Name: " << setw(12) << lastName;
		cout << setw(8) << "Email: " << setw(25) << email;
		cout << setw(8) << "Age: " << setw(6) << age;
		cout << setw(20) << "Days In Course: ";
		cout << "{ ";
		for (size_t i = 0; i < daysToComplete.size(); i++)
		{
			cout << daysToComplete.at(i);
			if (daysToComplete.size() > i + 1) {
				cout << ", ";
			}
		}
		cout << " }\t";

		cout << "Program: " << degreeProgramStrings[(int)degreeProgram] << "\n";
		break;
	}


}

/* Calling destructor function from student.h */
student::~student() {
	cout << "Destructor called for..." << endl;
}