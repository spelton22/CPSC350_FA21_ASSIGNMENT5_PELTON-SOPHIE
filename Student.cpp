/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    Student.cpp
*/

#include "Student.h"

Student::Student(){ //default constructor
  timeNeeded = 0;
  waitTime = 0;
  timeArrive = 0;
  timeAtWind = 0;
  timeLeave=0;
}

Student::Student(int tneed, int tArrive){ //overloaded constructor
  timeNeeded = tneed;
  waitTime = 0;
  timeArrive = tArrive;
  timeAtWind = 0;
  timeLeave = 0;
}

Student::~Student(){ //default destructor
}

void Student::updateTimeAtWindow(){//update how much time they need at the window (USED)
  ++timeAtWind;
}

int Student::getTimeAtWindow(){ //get how much time spent at the window (USED)
  return timeAtWind;
}

int Student::getTimeNeeded(){ //get how much time thye need at window (USED)
  return timeNeeded;
}

void Student::setTimeNeeded(int ntime){//set how much time they need at window
  timeNeeded = ntime;
}

int Student::getWaitTime(){ //time they have been waiting at waitlist
  return waitTime;
}

void Student::updateWaitTime(){ //time on waitlist
  ++waitTime;
}

int Student::getEnterTime(){ //time they can get off the waitlist
  return timeArrive;
}

void Student::setExitTime(int exit){ //time they leave waitlist
  timeLeave = exit;
}

void Student::setWaitTime(int wtime){ //set how much time they were on waitlist
  waitTime = wtime;
}

int Student::getExitTime(){ //get the time the student leaves the waitlist 
  return timeLeave;
}
