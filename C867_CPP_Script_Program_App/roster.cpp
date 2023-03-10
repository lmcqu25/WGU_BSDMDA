/* Rubric E. Creating a roster class using roster.cpp and roster.h */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <regex>

using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"

/* E3a. Defining public void add ... that sets variables from D1 and updates roster: */
void roster::add(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	degreeProgramEnum degreeprogram) {

	vector<int> addDaysInCourse{ daysInCourse1, daysInCourse2, daysInCourse3 };
	student* addStudent = new student(studentID, firstName, lastName, emailAddress, age, addDaysInCourse, degreeprogram);
	classRosterArray.push_back(addStudent);
}

/* E3b. Defining public void remove (string student ID) that removes students from
the roster by studentID. If student ID is not found, then create error indicating student not found. */
void roster::remove(string studentID) {
	bool foundItem = false;
	cout << "Removing student ID " << studentID << " from roster.\n";
	for (size_t i = 0; i < classRosterArray.size(); i++)
	{
		if (studentID == classRosterArray.at(i)->getStudentID()) {
			cout << "Student " << studentID << " successfully removed from roster.\n\n";
			delete classRosterArray.at(i);
			classRosterArray.erase(classRosterArray.begin() + i);
			foundItem = true;
		}
	}
	if (!foundItem) {
		cout << "No such student with this ID was found.\n\n";
	}
}

/* E3d. Defining public void printAverageDaysInCourse(string studentID) that prints 
a studnet's average number of days in the three courses, identified by their studentIDs. */
void roster::printAverageDaysInCourse(string studentID) {
	bool foundItem = false;
	float avgDaysResult = 0.00;
	cout << "Displaying average days in course for student " << studentID << ":  ";
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		if (studentID == classRosterArray.at(i)->getStudentID()) {
			vector<int> avgDaysVec = classRosterArray.at(i)->getdaysToComplete();
			for (size_t i = 0; i < avgDaysVec.size(); i++) {
				avgDaysResult = avgDaysResult + avgDaysVec.at(i);
			}
			cout << setprecision(4) << avgDaysResult / avgDaysVec.size() << "\n";
			foundItem = true;
		}
	}
	if (!foundItem) {
		cout << "Such a student with this ID was not found.\n\n";
	}
}

void roster::printAll() const {
	cout << "Displaying all students from roster: \n\n";
	for (size_t i = 0; i < classRosterArray.size(); i++)
	{
		classRosterArray.at(i)->print(printItemEnum::ALL);
	}
	cout << "\n";
}


/*E3e. Defining public void print InvalidEmails() that verifies student email addresses and 
displays all invalid email addresses to the user.*/
void roster::printInvalidEmails() {
	bool foundItem = false;
	cout << "Displaying students with invalid email addresses:\n\n";
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		const regex emailPattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		if (!regex_match(classRosterArray.at(i)->getEmailAddress(), emailPattern)) {
			cout << "Invalid email address found for Student ID: " << classRosterArray.at(i)->getStudentID();
			cout << "\t< " << classRosterArray.at(i)->getEmailAddress() << " >\n";
			foundItem = true;
		}
	}
	if (!foundItem) {
		cout << "Invalid email addresses not found\n";
	}
	cout << "\n";
}

/* E3f. Defining public void printByDegreeProgram, printing a degree program for students based on their individual enumerated types. */
void roster::printByDegreeProgram(degreeProgramEnum degreeProgram) {
	bool foundItem = false;
	cout << "Displaying all students in " << degreeProgramStrings[(int)degreeProgram] << " program:\n\n";
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		if (degreeProgram == classRosterArray.at(i)->getDegreeProgram()) {
			classRosterArray.at(i)->print(printItemEnum::ALL);
		}
		foundItem = true;
	}
	if (!foundItem) {
		cout << "Such a student with this ID was not found.\n";
	}
	cout << "\n";
}



roster::roster() {
	return;
}


roster::roster(const roster& origRoster) {
	cout << "Completed: Constructor called.\n\n";
	for (size_t i = 0; i < origRoster.classRosterArray.size(); i++) {
		classRosterArray.push_back(new student(*origRoster.classRosterArray.at(i)));
	}
	return;
}

roster::~roster() {
	cout << "Completed: Destructors will be called during exit.\n\n";
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		delete classRosterArray.at(i);
		classRosterArray.at(i) = nullptr;
	}
	return;
}