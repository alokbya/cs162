#ifndef messagelist_H
#define messagelist_H

#include "message.h"
struct Node
{
    Message * data;
    Node * next;
};

class messagelist
{
    private:
        Node *head;
    public:
        // Default constructor
        messagelist();
        // Destructor
        ~messagelist();
        // Add a message (node) to the linked list (messagelist)
        bool add(int id, char * name);
        // Remove a message (node) by it's unique identifier
        // (id), that is a message property.
        bool remove(int val);
        // Print all messages
        void print();
        // Print all messages that belong to (name)
        void print(char * name);
};

#endif