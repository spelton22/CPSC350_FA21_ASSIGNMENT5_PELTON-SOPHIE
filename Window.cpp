/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    Window.cpp
*/

#include "Window.h"

Window::Window(){ //default constructor
  idleTime = 0;
  isWinBusy = false;
  s = nullptr;
}

Window::Window(Student *student1){ //overloaded constrcutor
  idleTime = 0;
  isWinBusy = false;
  s = student1;
}

Window::~Window(){//default destructor

}

void Window::updateIdleTime(){ //updates idle time by 1
  ++idleTime;
}

int Window::getIdleTime(){ //returns idle time
  return idleTime;
}

bool Window::isWindowBusy(){ //returns if the window is busy
  return isWinBusy;
}

void Window::setBusyWindow(){ //sets if the window is busy -- true if busy
  isWinBusy = true;
}

Student* Window::getStudent(){//gets the student at the window
  return s;
}

void Window::setStudent(Student *st){ //sets the student at the window equal to the student passed in
  //done at window
  s = st;
}

Student* Window::removeStudent(){ //removes the student from the window and returns that student 
  //remove from window
  Student *temp = s;
  s = nullptr;
  return temp;
}
