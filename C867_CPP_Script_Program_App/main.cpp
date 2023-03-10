/* Rubric B. Please see the six files called main.cpp, student.cpp, student.h, roster.cpp, roster.h, and degree.h attached to meet Rubric B requests.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"




/* Rubric F. Required function call to parse StudentData, inputing it into the Roster class */
roster fromStudentData(const string studentData[], size_t numStudents);


int main()
{
/* Rubric F1. Print out to the screen, via your application, the course title, the 
programming language used, your WGU student ID, and your name */
    cout << "\t\t\t\t\t\t\t  __________________________________________________\n";
    cout << "\t\t\t\t\t\t\t |                                                  |\n";
    cout << "\t\t\t\t\t\t\t | Scripting and Programming - Applications - C867  |\n";
    cout << "\t\t\t\t\t\t\t |             Programming Language: C++            |\n";
    cout << "\t\t\t\t\t\t\t |               Student ID: 010457704              |\n";
    cout << "\t\t\t\t\t\t\t |               Logan Scott McQuillan              |\n";
    cout << "\t\t\t\t\t\t\t |__________________________________________________|\n\n\n";

/* Rubric A. Modifying the studentData table to include my personal information as
    the last item. */
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Logan,McQuillan,lmcqu25@wgu.edu,45, 30, 40, 50,SOFTWARE"};

    const size_t numStudents = sizeof(studentData) / sizeof(studentData[0]);

/* Rubric F2. Create an instance of the Roster class called classRoster. */ 
    roster classRoster = fromStudentData(studentData, numStudents);
    cout << "\n";


/* F4. Convert the following pseduo code to complete the rest of the
    main() function:...*/
    classRoster.printAll();
    classRoster.printInvalidEmails();

    cout << "Displaying average days in course for each student: \n\n";
    for (size_t i = 0; i < classRoster.classRosterArray.size(); i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray.at(i)->getStudentID());
    }
    cout << "\n";

    classRoster.printByDegreeProgram(degreeProgramEnum::SOFTWARE);
    classRoster.remove("A3");
    cout << "\n";
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;

    }

/* Rubric F5. Destructor to release memory dynamically stored in Roster.
Will use the destructor ~roster() from roster.cpp to release memory from Roster. 

InputStudentData function definition used above to call */

    roster fromStudentData(const string studentData[], size_t numStudents) {

        roster roster;

        for (size_t i = 0; i < numStudents; i++)
        {
            size_t rhs = studentData[i].find(",");
            string StudentIDInput = studentData[i].substr(0, rhs);

            size_t lhs = rhs + 1;
            rhs = studentData[i].find(",", lhs);
            string firstNameInput = studentData[i].substr(lhs, rhs - lhs);

            lhs = rhs + 1;
            rhs = studentData[i].find(",", lhs);
            string lastNameInput = studentData[i].substr(lhs, rhs - lhs);

            lhs = rhs + 1;
            rhs = studentData[i].find(",", lhs);
            string emailInput = studentData[i].substr(lhs, rhs - lhs);

            lhs = rhs + 1;
            rhs = studentData[i].find(",", lhs);
            int ageInput = stoi(studentData[i].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[i].find(",", lhs);
            int daysInClass1Input = stoi(studentData[i].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[i].find(",", lhs);
            int daysInClass2Input = stoi(studentData[i].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[i].find(",", lhs);
            int daysInClass3Input = stoi(studentData[i].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            degreeProgramEnum programInputEnum = degreeProgramEnum::SOFTWARE;
            string programInputString = studentData[i].substr(lhs, studentData[i].length() - lhs);
            int pIntECode = 12345;

            try {
                if (programInputString == "SECURITY") { programInputEnum = degreeProgramEnum::SECURITY; }
                else if (programInputString == "NETWORK") { programInputEnum = degreeProgramEnum::NETWORK; }
                else if (programInputString == "SOFTWARE") { programInputEnum = degreeProgramEnum::SOFTWARE; }
                else throw pIntECode;
            }
            catch (int pIntECode) {
                cout << "Degree program does not match." << endl;
            }

            roster.add(StudentIDInput, firstNameInput, lastNameInput, emailInput, ageInput, daysInClass1Input, daysInClass2Input, daysInClass3Input, programInputEnum);
        }
        return roster;
    }
    
        
    
    

