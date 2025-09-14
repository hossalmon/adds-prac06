#include "LinkedList.h"
#include <iostream>
#include <limits>

// default constructor - empty list
LinkedList::LinkedList() : head(nullptr) {}

// constructor from c-array
LinkedList::LinkedList(int* array, int len) : head(nullptr) {
    if (!array || len <= 0) return;

    // build by adding to tail
    Node* tail = nullptr;
    for (int i = 0; i < len; ++i) {
        Node* n = new Node(array[i], nullptr);
        if (!head) {
            head = n;
            tail = n;
        } else {
            tail->setLink(n);
            tail = n;
        }
    }
}

// destructor
LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr) {
        Node* next = curr->getLink();
        delete curr;
        curr = next;
    }
    head = nullptr;
}

// insert 'newNum' at position 'pos'
void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum, nullptr);

    // insert at front if list empty or pos <= 1
    if (pos <= 1 || head == nullptr) {
        newNode->setLink(head);
        head = newNode;
        return;
    }

    // go to node just before the desired position
    Node* prev = head;
    int index = 1;
    while(prev->getLink() != nullptr && index < pos - 1) {
        prev = prev->getLink();
        ++index;
    }

    // insert after 'prev'
    newNode->setLink(prev->getLink());
    prev->setLink(newNode);
}

// delete node at position 'pos'
bool LinkedList::deletePosition(int pos) {
    if (pos < 1 || head == nullptr) return false;

    // delete head
    if (pos == 1) {
        Node* toDelete = head;
        head = head->getLink();
        delete toDelete;
        return true;
    }

    // find node just before target
    Node* prev = head;
    int index = 1;
    while (prev != nullptr && prev->getLink() != nullptr && index < pos - 1) {
        prev = prev->getLink();
        ++index;
    }

    // out of bounds
    if (prev == nullptr || prev->getLink() == nullptr) {
        return false;
    }

    // delete pos
    Node* toDelete = prev->getLink();
    prev->setLink(toDelete->getLink());
    delete toDelete;
    return true;
}


// getdata at position 'pos'
int LinkedList::get(int pos) const {
    // if out of bounds, return max int
    if (pos < 1) return std::numeric_limits<int>::max();

    const Node* curr = head;
    int index = 1;
    while (curr != nullptr && index < pos) {
        curr = curr->getLink();
        ++index;
    }

    // out of bounds check agian - pos too large if nullptr hit
    if (curr == nullptr) return std::numeric_limits<int>::max();

    return curr->getData();
}

// search method
int LinkedList::search(int target) const {
    const Node* curr = head;
    int index = 1;
    while (curr != nullptr) {
        if (curr->getData() == target) return index;    // match found
        curr = curr->getLink();
        ++index;
    }

    // if target doesn't exist return -1
    return -1;
}

// print list method
void LinkedList::printList() const {
    if (head == nullptr) return;    // empty list prints nothing

    std::cout << "[";
    const Node* curr = head;    // ptr to go through the list (traversal)
    bool first = true;
    while (curr != nullptr) {
        if (!first) std::cout << " ";   // print space first if not 1st element
        std::cout << curr->getData();   // prints node's data
        first = false;
        curr = curr->getLink(); // move onto next node
    }
    std::cout << "]";
}
