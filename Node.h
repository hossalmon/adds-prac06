#ifndef NODE_H
#define NODE_H

class Node {
    private:
        int data;
        Node* link;

    public:
        // constructor
        Node(int data = 0, Node* link = nullptr); // last node points to nullptr

        // getter
        int getData() const;
        Node* getLink() const;

        // setter
        void setData(int d);
        void setLink(Node* next);

};

#endif 