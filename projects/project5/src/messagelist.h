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
        messagelist();
        ~messagelist();
        bool add(int id, char * name);//Message * &m);
        bool remove(int val);
        void print();
        void print(char * name);
};

#endif