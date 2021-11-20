/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    Simulation.h
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <exception>
#include "Student.h"
#include "GenQueue.h"
#include "Window.h"
#include "FileProcessor.h"

using namespace std;

class Simulation{
public:
  Simulation(); //default constructor
  Simulation(int nWindows); //overloaded constructor
  ~Simulation(); //default destructor
  void run(string inputfile); //method to run the simulation -- takes a input file so it can read the file and get the needed information

private:
  int numWindows; //memeber variable for the number of windows to open
  void sortList(int *a, int size); //member function to sorts the list from smallest to largest
  void calculateStudent(int *a, int size); //member function to calculate the needed information for the student
  void print(int *a, int size); //print the passed in array 
  void calculateWindow(int *a, int size); //member function to calculate the needed information for the window
};

#endif
