/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    Student.h
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <exception>
using namespace std;

class Student{
public:
  Student();//default destructor
  Student(int need, int tArrive); //overloaded constructor
  ~Student();//default destructor
  int getTimeNeeded();//get how much time they need at the window
  void setTimeNeeded(int ntime);//set how much time student needs at the window
  int getWaitTime();//get how much time they waited in waitlist
  void updateWaitTime();//time on waitlist
  int getEnterTime();//time they can get off the waitlist
  void updateTimeAtWindow();//update how much time they need at the window
  int getTimeAtWindow();//get how much time spent at the window
  void setExitTime(int exit);//set the time they leave the waitlist
  int getExitTime();//get the time they leave the waitlist
  void setWaitTime(int wtime);//set how much time they were on waitlist
private:
  int timeNeeded;//how much time needed at window
  int waitTime;//how much time spent in waitline
  int timeArrive;//time they can get off waitlist
  int timeAtWind; //time spent at the window
  int timeLeave; //time they leave the waitlist
};

#endif
