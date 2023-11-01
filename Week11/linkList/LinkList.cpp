#include "linkList.h"

LinkedList::LinkedList(){
    mHead=nullptr;
    mSize=0;
}
/*
void LinkedList::add(double number)
{
    if (mSize==0){
        mHead = new Node(number);
    } else{
        Node * ptr=mHead;
        //find the end of the list
        while(ptr->next!=nullptr){
            ptr=ptr->next;
        }
        ptr->next=new Node(number);
    }
    mSize++;
}*/

std::string LinkedList::toStringR() const
{
    std::ostringstream ostr;
    return toStringR(mHead, ostr);
}

std::string LinkedList::toStringR(Node *ptr, std::ostringstream &out) const
{
    if (ptr == nullptr)
    {
        return out.str();
    }
 
    out << ptr->data << " ";
    return toStringR(ptr->next, out);
}
LinkedList::~LinkedList(){
    while (mHead != nullptr)
    {
        // keep track of node to be deleted
        Node *nodeToDelete = mHead;
        // Move on to the next node, if any
        mHead = mHead->next;
        // Fully isolate the node to be deleted
        nodeToDelete->next = nullptr;
        // Delete the node
        delete nodeToDelete;
    }

}

void LinkedList::addR(double number)
{
    addR(number, mHead);
}
void LinkedList::addR(double number, Node * ptr){
    if (ptr==nullptr){//list is empty
        mHead = new Node(number);
    }
    else if (ptr->next == nullptr){
        ptr->next=new Node(number);
    } else{
        addR(number, ptr->next);
    }
    mSize++;
}
