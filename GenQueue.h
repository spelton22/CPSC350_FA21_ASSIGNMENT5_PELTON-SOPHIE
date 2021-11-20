/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    GenQueue.h
*/

#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>
#include "MyList.h"

using namespace std;

template <typename T>
class GenQueue{
  public:
    GenQueue(); //default constructor
    ~GenQueue(); //default destructor

    //core fucntions
    void enqueue(T data); //aka insert()
    T dequeue(); //aka remove()

    //auxilary functions
    T peek(); //returns the first element of the queue
    bool isEmpty(); //returns if the queue is empty
    void printQueue(); //prints the queue
    unsigned int getLen(); //gets the size of the GenQueue

  private:
    MyList<T> *list; //member variable for list to call methods from list class
    int length; //length of the queue
};

template <typename T>
GenQueue<T>::GenQueue(){ //default constructor
  list = new MyList<T>();
  length = 0;
}

template <typename T>
GenQueue<T>::~GenQueue(){ //default destructor
}

//aka insert
template <typename T>
void GenQueue<T>::enqueue(T data){ //insert data to end of queue
  list->append(data);
  ++length;
}

template <typename T>
void GenQueue<T>::printQueue(){ //prints the queue -- calls method from list class
  list->print();
}

//aka remove
template <typename T>
T GenQueue<T>::dequeue(){ //removes the frist element from queue
  T value = list->remove();
  --length;
  return value;
}

template <typename T>
T GenQueue<T>::peek(){ //retruns the first element of the queue
  T value = list->getFront();
  return value;
}

template <typename T>
bool GenQueue<T>::isEmpty(){ //checks if queue is empty
  return (length == 0);
}

template <typename T>
unsigned int GenQueue<T>::getLen(){ //gets the length of the queue
  return length;
  //list->getLength();
}

#endif
