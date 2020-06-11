#include "list.h"

#include <iostream>
using namespace std;

//put the implementation of your assigned functions here
int countEven(node *head)
{
    int count = 0;
    node *current = nullptr;
    current = head;
    while(current)
    {
        if(!(current->data % 2))
            count++;
        current = current->next;
    }
    return count;
}

int removeEven(node *&head)
{
    int count = 0;
    node *current = nullptr;
    node *next = nullptr;
    node *prev = nullptr;

    current = head;

    while(!(current->data % 2))                         // if head is even, keep looping until no more even heads
    {
        count++;
        head = head->next;
        delete current;
        current = head;
    }
    
    prev = head;                                        // before checking through the middle of the list, set prev to head, and current to head->next
    current = current->next;                            // i.e. head->next
    
    
    while (current->next)                               // iterate through list while current is NOT a nullptr
    {
        if(!(current->data % 2))                              // if current is even
        {
            next = current->next;
            prev->next = next;
            delete current;
            current = next;
            count++;
        }
        else
        {
            current = current->next;
            prev = prev->next;
        }
        
    }

    // check the tail end
    if(!(current->data % 2))
    {
        count++;
        prev->next = nullptr;
        delete current;
    }

    return count;
}