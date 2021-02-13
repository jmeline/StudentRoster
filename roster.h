/*! \class roster
 *  \brief Brief class description
 *
 *  Detailed description
 */

#ifndef _ROSTER_H_
#define _ROSTER_H_

#include <string>
#include <vector>
#include "student.h"
#include "degree.h"

const int MAX_STUDENTS = 10;

class roster
{
  public:
    roster() {
      rosterCount = 0;
    };

    void add(
        std::string studentId,
        std::string firstName,
        std::string lastName,
        std::string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);

    void remove(std::string studentId);
    void printAll();
    void printAverageDaysInCourse(std::string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

  private:
    student* classRosterArray[MAX_STUDENTS];
    int rosterCount;
};
#endif /* _ROSTER_H_ */
