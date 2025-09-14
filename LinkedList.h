#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <limits>

class LinkedList {
    private:
        Node* head;     // ptr to first node in lsit
    
    public:
      // constructor + destructor
      LinkedList();     // creates empty lsit
      LinkedList(int* array, int len);  // constructor from a c-array
      ~LinkedList();

      // methods
      void insertPosition(int pos, int newNum);
      bool deletePosition(int pos);
      int get(int pos) const;
      int search(int target) const;
      void printList() const;

};

#endif