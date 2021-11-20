/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    main.h
*/

#include <iostream>
#include "GenQueue.h"
#include "Simulation.h"

using namespace std;

int main(int argc, const char *argv[]){

  string inputFile=""; // variable to store the command line argument
  Simulation *sim = new Simulation(); //simulation object for method run()

  try{
    if(argc == 2){ //checks if there is any given input
      inputFile = argv[1]; //stores the given input file
    }else if(argc <=1){ //handles no input given
      cout << "you did not enter a file an input file. Please give a file name to read : " << endl;
      cin >> inputFile; //reading in file from user
    }else if(argc >2){ //handles too many arguments
      cout << "you gave too many arguments. Please give a file name to read : " << endl;
      cin >> inputFile; //reading in new file from user
    }

    sim->run(inputFile); //runs the simulation
      //output printed tro screen

  }
  catch(runtime_error &excpt){ //catches any run time errors
      cerr << excpt.what() << endl;
      //catch errors and prints it to the console
  }

  //delete queue;
  delete sim;
  return 0;

}
