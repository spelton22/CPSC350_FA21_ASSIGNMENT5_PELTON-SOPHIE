/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    FileProcessor.h
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
#include "Window.h"
#include "Simulation.h"
#include "GenQueue.h"

using namespace std;

class FileProcessor{
  public:
    FileProcessor(); //default constructor
    ~FileProcessor(); //default destructor
    int processFile(string in, GenQueue<Student *> *waitLine); //processes the file, pass in the input file to read and the queue to add students to -- returns the number of windows to open
};

#endif
