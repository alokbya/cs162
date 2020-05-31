//put your implementation of LinkedList class here
#include "list.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}   
LinkedList::~LinkedList()
{
    Node *current = head;
    Node *next = nullptr;
    while(current)
    {
        next = current->next;
        delete current;
        current = next;
    }
    // delete current;
}

bool LinkedList::addAtBeginning(int val)
{
    Node *n = nullptr;
    n = new Node;
    n->data = val;
    n->prev = nullptr;                      
    n->next = nullptr;                  // causing major headache, MUST initialize
    
    if(head)                            // if head is not a nullptr;
    {
        n->next = head;
        head->prev = n;
    }
    else
        tail = n;
    head = n;
    return true;
}

bool LinkedList::remove(int val)
{
    // iterate through the list until last node (nullptr)
    // if val is found, delete node, return true
    bool found = false;
    Node *current = head;
    Node *trailCurrent = nullptr;

    Node *toDelete = nullptr;
    while(current && !found)
    {
        if(current->data == val)
        { 
            toDelete = current;
            found = true;
        }
        current = current->next;
    }
    // if the list is empty toDelete == head == nullptr
    if(!toDelete)
        found = false;
    // if item is in first node of the list
    else if(toDelete == head)
    {   
        current = head;
        head = head->next;
        head->prev = nullptr;
        delete current;
    }
    else if(toDelete == tail)
    {
        current = tail;
        trailCurrent = current->prev;
        trailCurrent->next = nullptr;
        tail = trailCurrent;
        delete current;
    }
    else                                                                        // toDelete is in the middle
    {
        current = toDelete;
        trailCurrent = current->prev;
        trailCurrent->next = current->next;
        current->next->prev = trailCurrent;
        delete current;
    }
    
    return found;
}

void LinkedList::printForward() const
{
    Node *current = nullptr;
    if(head)
        current = head;
    while(current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::printBackward() const
{
    Node *current = tail;
    while (current)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;

}
