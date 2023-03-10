/* Rubric E. Creating a roster class using roster.cpp and roster.h */
#pragma once


/* Rubric E1 and E2. Creating an array, classRosterArray, containing data from studentData table. 
Creating student objects for individual students from studentData table to populate classRosterArray. */

class roster
{
public:
	vector<student*> classRosterArray;
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		degreeProgramEnum degreeprogram);
	void remove(string studentID);

	/* Creating print function. */
	void printAll() const;
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(degreeProgramEnum degreeProgram);
	void printInvalidEmails();

	/* Declaring constructor */
	roster();

	/* Declaring destructor */
	~roster();

	/* Copying contructor for inputStudentData. */
	roster(const roster& origRoster);
};