#include "roster.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
#include <utility>

void roster::add(
    std::string studentId,
    std::string firstName,
    std::string lastName,
    std::string emailAddress,
    int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgram degreeProgram
)
{
  int daysInCourse[] = {
    daysInCourse1,
    daysInCourse2,
    daysInCourse3
  };

  student *newStudent = new student(
      studentId,
      firstName,
      lastName,
      emailAddress,
      age,
      daysInCourse,
      degreeProgram
      );

  classRosterArray[rosterCount++] = newStudent;
}

void roster::remove(std::string studentId) {
  int found = -1;
  for (int i = 0; i < rosterCount; i++) {
    if (classRosterArray[i]->getStudentId() == studentId) {
      found = i;
    }
  }

  if (found == -1) {
    std::cout << "Student: "
      << studentId
      << " was not found in the roster"
      << std::endl;
    return;
  }

  // student was found in the roster
  classRosterArray[found] = NULL;
  rosterCount--;
}

void printStudent(student* student) {

  int* dayInCourseArr = student->getDaysInCourse();
  std::string daysInCourse = "{"
    + std::to_string(dayInCourseArr[0])
    + std::to_string(dayInCourseArr[1])
    + std::to_string(dayInCourseArr[2])
    + "}";

  std::cout
    << "First Name: \t" << student->getFirstName()
    << "LastName Name: \t" << student->getLastName()
    << "Age: \t" << std::to_string(student->getAge())
    << "daysInCourse: \t" << daysInCourse
    << "Degree Program: \t" << student->getDegreeProgram()
    << std::endl;
}

void roster::printAll() {
  for (int i = 0; i < rosterCount; i++) {
     printStudent(classRosterArray[i]);
  }
}


void roster::printAverageDaysInCourse(std::string studentId) {
  student* foundStudent = NULL;
  for (int i = 0; i < rosterCount; i++) {
    if (classRosterArray[i]->getStudentId() == studentId) {
      foundStudent = classRosterArray[i];
    }
  }

  if (foundStudent == NULL) {
    std::cout << "Couldn't find student: " << studentId << std::endl;
    return;
  }


  int total = 0;
  for (int i = 0; i < 3; i++) {
    total += foundStudent->getDaysInCourse()[i];
  }
  std::cout << "Average Days in Course: " << (total / 3) << std::endl;
}


void validateEmail(student* student) {
  std::string emailAddress = student->getEmailAddress();
  std::string studentInfo = student->getFirstName() + " (" + student->getStudentId() + ") ";
  bool isValid = true;

  std::size_t found = emailAddress.find(" ");
  // failed: email address contained spaces
  if (found != std::string::npos) {
    std::cout << studentInfo << "has a space in their email address at pos (" << found << ")" << std::endl;
    isValid = false;

  }
  found = emailAddress.find("@");
  // failed: email address missing "@"
  if (found == std::string::npos) {
    std::cout << studentInfo << "is missing an @ sign in their email address at pos (" << found << ")" << std::endl;
    isValid = false;
  }

  found = emailAddress.find(".");
  // failed: email address missing "."
  if (found == std::string::npos) {
    std::cout << studentInfo << "is missing a . sign in their email address at pos (" << found << ")" << std::endl;
    isValid = false;
  }

  if (isValid) {
    std::cout << studentInfo << "had a valid email!" << std::endl;
  }
}

void roster::printInvalidEmails() {
  for (int i = 0; i < rosterCount; i++) {
    validateEmail(classRosterArray[i]);
  }
}

void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
  for (int i = 0; i < rosterCount; i++) {
    if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
      std::cout << classRosterArray[i]->getStudentId() << "is in " << degreeProgram << std::endl;
    }
  }
}
