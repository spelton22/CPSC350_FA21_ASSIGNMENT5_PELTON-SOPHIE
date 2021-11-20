/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 5
    MyList.h
*/

#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <exception>
#include "DoublyLinkedList.h"
using namespace std;

template <typename T>
class ListInterface{ //pure virtual interface class for a List
protected:
  ListInterface() {}; //default constructor
  ~ListInterface() {}; //default destructor
public:
  virtual void append(T data)=0; //insert end
  virtual void prepend(T data)=0; //insert front
  virtual T remove()=0; //remove first element
  virtual int search(T data)=0; //search for data in the list
  virtual void print()=0; //print the list
  virtual bool isEmpty()=0; //check if list is empty
  virtual unsigned int getLength()=0; //get length of the list
  virtual T getFront()=0; //get front element of the list

};

template <typename T>
class MyList : public ListInterface<T>{ //template class for list using thr list interface functions
private:
  DoublyLinkedList<T> *dll; //member variable for DoublyLinkedList to call its methods
public:
  MyList<T>(); //default constructor
  ~MyList(); //default destructor
  void append(T data); //instert back
  void prepend(T data); //insert front
  T remove(); //remove first element
  int search(T data); //search for data in the list
  void print(); //print the list
  bool isEmpty(); //check if list is empty
  unsigned int getLength(); //get the length of the list
  T getFront(); //get the front of the list

};

template <typename T>
MyList<T>::MyList(){ //default constructor
  dll = new DoublyLinkedList<T>();
}

template <typename T>
MyList<T>::~MyList(){ //default destructor
}

template <typename T>
void MyList<T>::append(T data){//insert end
  dll->insertBack(data);
}

template <typename T>
void MyList<T>::prepend(T data){ //insert front
  dll->insertFront(data);
}

template <typename T>
T MyList<T>::remove(){ //remove front of the list
  return dll->removeFront();
}

template <typename T>
int MyList<T>::search(T data){ //search for data in the list
  return dll->find(data);
}

template <typename T>
void MyList<T>::print(){//print the list
  dll->printList();
}

template <typename T>
bool MyList<T>::isEmpty(){ //checks if the list is empty
  return dll->isEmpty();
}

template <typename T>
unsigned int MyList<T>::getLength(){ //get the length of the list
  return dll->getSize();
}

template <typename T>
T MyList<T>::getFront(){//get the front element of the list
  return dll->getFront();
}

#endif
