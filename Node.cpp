#include "Node.h"

// constructor
Node::Node(int data, Node* link) : data(data), link(link) {}

// getters
int Node::getData() const {
    return data;
}

Node* Node::getLink() const {
    return link;
}

// setters
void Node::setData(int d) {
    data = d;
}

void Node::setLink(Node* next) {
    link = next;
}