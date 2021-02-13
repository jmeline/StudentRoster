#ifndef STUDENT_H
#define STUDENT_H

#include<string>

#include "degree.h"

/*
 * *****************
 * * class student *
 * *****************
 *  I'm a student, duh
 */

class student
{
  public:
    student(
      std::string studentId,
      std::string firstName,
      std::string lastName,
      std::string emailAddress,
      int age,
      int* daysInCourse,
      DegreeProgram program
    );

    void print();

    /* setters */
    void setStudentId(std::string id)                    { studentId = id; };
    void setFirstName(std::string firstName)             { this->firstName = firstName; };
    void setLastName(std::string lastName)               { this->lastName = lastName; };
    void setAge(int age)                                 { this->age = age; };
    void setEmailAddress(std::string emailAddress)       { this->emailAddress = emailAddress; };
    void setDegreeProgram(DegreeProgram degreeProgram)   { this->degreeProgram = degreeProgram; };

    /* getters */
    int getAge()                        { return age; };
    int* getDaysInCourse()              { return daysInCourse;  };
    std::string getStudentId()          { return studentId;     };
    std::string getFirstName()          { return firstName;     };
    std::string getLastName()           { return lastName;      };
    std::string getEmailAddress()       { return emailAddress;  };
    DegreeProgram getDegreeProgram()    { return degreeProgram; };


  private:
    int age;
    std::string studentId;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int* daysInCourse;
    DegreeProgram degreeProgram;
};

#endif /* STUDENT_H */
