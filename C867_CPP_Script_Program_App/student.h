/* Rubric D. For the Student class, do the following:
   Create the class Student in the files student.h and student.cpp*/
#pragma once



/* Printing information for each student from the enumerated class. */
enum class printItemEnum { STUDENTID, FIRSTNAME, LASTNAME, EMAIL, AGE, DEGREEPROGRAM, DAYSTOCOMPLETE, ALL };



class student
{
private:
	int age;
	degreeProgramEnum degreeProgram;
	string studentID, firstName, lastName, email;
	vector<int> daysToComplete;

/* Rubric D2a. creating getters/accessors for variables from part D1. */

public:
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	degreeProgramEnum getDegreeProgram() const;
	vector<int> getdaysToComplete() const;

/* Rubric D2b. Creating setters/mutators for variables from part D1. */
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string email);
	void setAge(int age);
	void setDegreeProgram(degreeProgramEnum degreeProgram);
	void setdaysToComplete(vector<int> daysToComplete);

/* Rubric D2d. Contructor using all input parameters in table. */ 
	student(
		string StudentID = "NEW",
		string firstName = "NEW",
		string lastName = "NEW",
		string email = "NEW",
		int age = 0,
		vector<int> daysToComplete = { 0, 0, 0, 0 },
		degreeProgramEnum degreeProgram = degreeProgramEnum::SOFTWARE);

/* Rubric D2e. Printing specific student data. */
	void print(printItemEnum printItem) const;

/* Declaring destructor function */
	~student();
};