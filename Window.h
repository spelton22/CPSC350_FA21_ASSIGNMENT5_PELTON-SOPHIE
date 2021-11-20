/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    Window.h
*/

//update idel time clock tick afte person left
//student left at 5 at 6 update idle time


#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <exception>
#include "Student.h"
using namespace std;

class Window{
public:
  Window();//default constructor
  Window(Student *student1);//overloaded constructor
  ~Window();//default destructor
  void updateIdleTime();//increments the idle time by one
  int getIdleTime();// gets the window idle time
  bool isWindowBusy();// checks if the window has a student
  void setBusyWindow();//set the student to busy if there is a student at the window
  Student* getStudent();// gets the student at the window
  void setStudent(Student *st);//sets the passed in student to the student at the window
  Student* removeStudent();//removes the student at the window
private:
  int idleTime;//member variable for the idle time of the window
  bool isWinBusy; //member variable for if the window is busy or empty
  Student *s; //member variable of a student object for the student at a window
};

#endif
