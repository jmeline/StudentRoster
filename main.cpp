#include<iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"

int main(int argc, char *argv[])
{
  roster *studentRoster = new roster();
  std::cout << "Hello Roster dumb program" << std::endl;

  studentRoster->add("A1", "John", "Smith", "john1998@ gmail.com", 20, 30, 35, 40, SECURITY);
  studentRoster->add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
  studentRoster->add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
  studentRoster->add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
  studentRoster->add("A5", "Jacob", "Meline", "jacob.meline@gmail.com", 33, 50, 58, 40, SOFTWARE);

  std::cout << "**************" << std::endl;
  std::cout << "** PRINT ALL *" << std::endl;
  std::cout << "**************" << std::endl;
  studentRoster->printAll();
  std::cout << "**************" << std::endl;

  std::cout << "*****************************" << std::endl;
  std::cout << "** PRINT ALL Invalid Emails *" << std::endl;
  std::cout << "*****************************" << std::endl;
  studentRoster->printInvalidEmails();
  std::cout << "*****************************" << std::endl;

  // do other stuff
  return 0;
}
