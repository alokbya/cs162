#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::~LinkedList()
{
    Node * current = head;
    Node * next = nullptr;
    while(current)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

bool LinkedList::add(Message * &m)
{
    Node * n = nullptr;
    n = new Node;
    n->data = m;
    n->next =  head;
    head = n;
    return true;
}

bool LinkedList::remove(int val)
{
    Node * current = nullptr;
    Node * tail = nullptr;
    Node * del = nullptr;
    Node * next = nullptr;
    bool found = false;

    if(head)
        current = head;
    if(current->data->getId() == val)
    {
        // head is to be deleted
        head = current->next;
        del = current;
    }
    else
    {
        while (current && !found)
        {
            if(current->next->data->getId() == val)
            {
                tail = current;
                del = current->next;
                next = del->next;
                found = true;
            }
        }
    }
    if(del)
    {
        tail->next = next;
        delete del;
    }

    return found;
}

void LinkedList::print()
{
    Node * current = nullptr;
    if(head)
        current = head;
    while(current)
    {
        cout << current->data->getId() << " ";
        current = current->next;
    }
    cout << endl;
}