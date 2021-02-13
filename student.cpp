#include "student.h"
#include <string>

student::student(
  std::string studentId,
  std::string firstName,
  std::string lastName,
  std::string emailAddress,
  int age,
  int *daysInCourse,
  DegreeProgram degreeProgram
)
{
  this->studentId = studentId;
  this->firstName = firstName;
  this->lastName = lastName;
  this->emailAddress = emailAddress;
  this->age = age;
  this->daysInCourse = daysInCourse;
  this->degreeProgram = degreeProgram;
}
