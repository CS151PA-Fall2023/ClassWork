#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include <string>
#include <sstream>

class LinkedList
{
public:
    LinkedList();                  // default constructor
    ~LinkedList();                 // destructor
    //void add(double number);
    void addR(double number);
    //void remove(double number);
    //std::string toString() const;
    std::string toStringR() const;     // recursive
    //unsigned int size() const;
    //unsigned int sizeR() const;   // recursive

private:
    struct Node{
       int data;
       Node * next;
       Node(int d = 0, Node* p = nullptr)
       {
            data = d;
            next = p;
       }
    };
    Node *mHead;                  // list head pointer
    unsigned int mSize;           // size of the list

    // helper functions 
    //unsigned int sizeR(Node *ptr) const;
    std::string toStringR(Node *ptr, std::ostringstream &out) const;
    void addR(double number, Node *ptr);
};


#endif