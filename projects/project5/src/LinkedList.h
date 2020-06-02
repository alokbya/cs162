#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "message.h"
struct Node
{
    Message * data;
    Node * next;
};

class LinkedList
{
    private:
        Node *head;
    public:
        LinkedList();
        ~LinkedList();
        bool add(Message * &m);
        bool remove(int val);
        void print();
};

#endif