/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    FileProcessor.cpp
*/

#include "FileProcessor.h"

FileProcessor::FileProcessor(){
  //default constructor
}

FileProcessor::~FileProcessor(){
  //default destructor
}

int FileProcessor::processFile(string input, GenQueue<Student *> *waitLine){
  //creates an input stream to read from a file
  std::ifstream myfileIN;
  std::string line;

  //opens the input file for reading
  myfileIN.open(input, ios::in);
  //gets the first line of the file and saves it to line
  getline(myfileIN, line);

  int numWindows = 0; //varaible for the number of windows to open read from the file
  sscanf(line.c_str(), "%d", &numWindows); //converts a string to an int

  Student *s = new Student(); //student object for saving the data of each student
  string tarrive=""; //time that a student arrives to the registrar office -- string
  int timeArrive = 0; //time that a student arrives to the registrar office -- int
  string numS = ""; //number of students for remembering how many students come at the specified time -- string
  int numStudents = 0; //number of students for remembering how many students come at the specified time -- int
  string tneeded =""; //how much time each student needs -- string
  int timeNeeded = 0;//how much time each student needs -- int

  //checks if the input and output file is open
  if (myfileIN.is_open() ){
    //for loop to go through each line of the file
    for(std::string line; (std::getline(myfileIN, tarrive, '\n')); ){
      sscanf(tarrive.c_str(), "%d", &timeArrive); //first line that is read in for the loop is the time the student arrives -- convert to an int

      getline(myfileIN, numS); //get the next line -- number of students
      sscanf(numS.c_str(), "%d", &numStudents); //convert string to int

      for(int i = 0; i < numStudents ; ++i){ //look to get data for specified num of students
        getline(myfileIN, tneeded); //get line -- time student needs
        sscanf(tneeded.c_str(), "%d", &timeNeeded); //convert string to int

        s = new Student(timeNeeded, timeArrive); //create a student obejct with information
        waitLine->enqueue(s); //add student to the wait line GenQueue
      }
    }
  }
  //closes both files after done using them
  myfileIN.close();
  //returns the number of windows
  return numWindows;
}
