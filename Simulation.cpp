/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    Simulation.cpp
*/

#include "Simulation.h"

Simulation::Simulation(){ //default constructor
  numWindows = 0;
}

Simulation::Simulation(int nwind){ //overloaded constructor
  numWindows = nwind;
}

Simulation::~Simulation(){ //default destructor
}

void Simulation::run(string inputFile){ //method to run the simulation

  FileProcessor *fp = new FileProcessor(); //instance of FileProcessor class
  GenQueue<Student *> *waitLine = new GenQueue<Student *>(); //instance of genqueue to wait line of students
  Student *s; //student object to be placed in the line
  int numWindows = 0; //number of windows to be opened
  numWindows = fp->processFile(inputFile, waitLine); //process file with input file, and queue for students to be placed in -- returns the number of windows to be opened
  Window **window = new Window*[numWindows]; //window array with size specificed from input file
  int count = 0; //count for number of windows empty
  int clock = 0; //clock time
  Student *studentAtWindow; //student object to add student to a window
  Student *studentAtBusy; //student object to represent a student at a window
  GenQueue<int> *endPile = new GenQueue<int>(); //queue for the students to be added when they finish their time at the window
  unsigned int numStudents = waitLine->getLen(); //number of students in wait line
  int endList[numStudents]; //array for the students when they are finished
  int windowIdleArray[numWindows]; //array for windows -- for calculations

  for(int i=0; i<numWindows ; ++i){ //for loop to instanciate each window
    window[i] = new Window();
  }

  while(true){
    for(int i = 0 ; i < numWindows; ++i){ //for loop to iterate over all windows
      if(window[i]->getStudent() == nullptr){ //checks if window is empty
        ++count; //increases count of number of windows empty
      }
    }

    if(waitLine->isEmpty() && count == numWindows){ //if there is no one in the waitlist and all the windows are empty
      break; //break the loop because the simulation is done
    }
    else{ // waitline is not empty or all windows are not empty
      count = 0; //reset count for next iteration
      for(int i = 0; i < numWindows; ++i){ //for loop to go over all the windows
        if(window[i]->getStudent() == nullptr){//window is not busy

          if(waitLine->getLen() != 0){ //for when there are people in the wait line
            if(waitLine->peek()->getEnterTime() <= clock) { //student can come off waitLine
              studentAtWindow = waitLine->dequeue(); //take them off waitLine
              studentAtWindow->setExitTime(clock); //set time they left waitLine
              window[i]->setStudent(studentAtWindow); //place student at window
            }
            else{ //student cannot come off waitlist
              window[i]->updateIdleTime(); //increase idle time for window
            }
          }else{ //when there is no one on the waitlist
            window[i]->updateIdleTime(); //increase idle time for window
            continue;
          }
        }else{ //window is busy
          studentAtBusy = window[i]->getStudent(); //get student at window
          studentAtBusy->updateTimeAtWindow(); //increase time at window by 1
          int timeWindow = studentAtBusy->getTimeAtWindow(); //time student has been at the window
          if(timeWindow == studentAtBusy->getTimeNeeded()){ //if they have been there for their time needed
            int waitTime = studentAtBusy->getExitTime() - studentAtBusy->getEnterTime(); //time arrive - time leave wait
            studentAtBusy->setWaitTime(waitTime); //sets the time student waited in line

            Student *temp = window[i]->removeStudent(); //saves information of student at that window

            endPile->enqueue(temp->getWaitTime());
            //send student to end queue --> go through method to sort for wait time
            //if statement check if the student in waitline -- get enter time == clock
            if(waitLine->getLen() != 0){ //for when there are people in the wait line
              if(waitLine->peek()->getEnterTime() <= clock) { //check if the student can be taken off the waitlist
                studentAtWindow = waitLine->dequeue(); //take them off waitLine
                studentAtWindow->setExitTime(clock); //set time they left waitLine
                window[i]->setStudent(studentAtWindow); //place student at window
              }
            }

          }
        }
      }
      ++clock; //increase clock tick
    }
  }

  for(int i=0; i<numWindows ; ++i){ //for loop to instanciate the window array with idle times
    windowIdleArray[i] = window[i]->getIdleTime();
  }

  for(int i = 0; i< numStudents; ++i){ //for loop to insatntiate end list of students wait time
    endList[i] = endPile->dequeue();//take element off of queue and add to array
  }

  sortList(endList, numStudents); //sort the list of student wait times
  sortList(windowIdleArray, numWindows); //sort array of window idle times
  calculateStudent(endList, numStudents); //calculate student metrics
  calculateWindow(windowIdleArray, numWindows);//calculate window metrics


}

void Simulation::sortList(int *a, int size){ //sorts the array passed in
  int min;
  int temp;
  for (int i = 0; i < size - 1; ++i) {
    min = i;
    for (int j = i + 1; j < size; ++j){
      if (a[j] < a[min]){
        min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
      }
    }
  }
}

void Simulation::print(int *a, int size){ //prints the elements of the array passed in
  for(int i =0; i<size; ++i){
    cout<< a[i] << endl;
  }
}

void Simulation::calculateStudent(int *a, int size){ //calculates the students metrics
  //mean time stuent
  //median wait time of student
  //longest student wait time
  //number of students waiting over 10 minututes

  double sum = 0;
  int countTen = 0;
  int longestTime = a[size-1]; //longest time is the last element of the sorted array
  int middleIndex = (size/2);
  int medianTime = a[middleIndex];
  int mean = 0;

  for(int i = 0; i < size; ++i){ //for loop to calculate sum
    sum += a[i];
    if(a[i] >= 10){
      ++countTen;
    }
  }

  mean = (int)(sum/((double)size));


  cout << "1. mean student wait time: " << mean << endl;
  cout << "2. median student wait time: " << medianTime << endl;
  cout << "3. longest student wait time: " << longestTime << endl;
  cout << "4. number of students waiting over 10 minutes: " << countTen << endl;
}

void Simulation::calculateWindow(int *a, int size){ //calculates the window metrics
  //mean idle time
  //longest window idle time
  //number of windows idle for 5 minutes
  int sum = 0;
  int mean = 0;
  int longest = a[size-1];
  int numFive = 0;

  for(int i = 0; i < size; ++i){ //for loop to sum up windows idle time
    sum += a[i];
    if(a[i] >= 5){
      ++numFive;
    }
  }

  mean = (sum/size);

  cout << "5. mean window idle time: " << mean << endl;
  cout << "6. longest window idle time: " << longest << endl;
  cout << "7. number of window idle for over 5 minutes: " << numFive << endl;

}
