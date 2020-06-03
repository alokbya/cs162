#include <iostream>
#include <cstring>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::~LinkedList()
{
    if(head)                                    // if any nodes are left
    {
        Node * current = head;
        Node * next = nullptr;
        Message * cm = current->data;
        // Message * nm = nullptr;

        while(current)
        {
            next = current->next;
            // if(next)                            // no data exists if current == nullptr
            //     nm = next->data;                                  
            delete cm;
            delete current;
            
            current = next;
            if(current)
                cm = current->data;             // no data exists if current == nullptr
        }
    }

}

bool LinkedList::add(int id, char* name)
{
    Message * m = new Message(id, name);
    Node * n = nullptr;         // instantiate new node
    n = new Node;               // allocate mem for new node
    n->data = m;                // set node.data pointer
    n->next =  head;
    head = n;
    return true;
}

bool LinkedList::remove(int val)
{
    Node * current = nullptr;
    Node * next = nullptr;
    Node * prev = nullptr;

    Node * del_n = nullptr;
    Message * del_m = nullptr;
    bool found = false;

    // check if val is in head
    if(head->data->getId() == val)
    {
        del_n = head;
        del_m = head->data;
        current = head->next;
        head = current;
    }
    else
    {
        if(head)
        {
            current = head;
            while(current->next && !found)
            {
                if(current->next->data->getId() == val)
                {
                    prev = current;
                    if(current->next->next)
                        next = current->next->next;
                    else
                        next = nullptr;
                    del_n = current->next;
                    del_m = current->next->data;
                    prev->next = next;
                    found = true;
                }
                else
                {
                    current=current->next;              
                }
                
            }
        }
    }
    
    
    if(del_n)
    {
        delete del_m;
        delete del_n;
    }

    return found;
}

void LinkedList::print()
{
    cout << "** All Messages **" << endl;
    Node * current = head;

    // find tail* and total count
    int count = 0;
    while(current)
    {
        current = current->next;
        count++;
    }
    // create an array of messages
    Message ** list = new Message*[count + 1]; 
    int i = 0;
    current = head;
    while(current)
    {
        Message * m = new Message(current->data->getId(), current->data->getRecipient());
        list[i] = m;
        i++;
        current = current->next;
    }
    // print ordered list
    for(int i = count-1; i >= 0; i--)
        if(list[i])
            cout << "Message " << list[i]->getId() << " " << list[i]->getRecipient() << endl;
    // delete (deallocate) memory
    for(int j = 0; j < count; j++)
           delete list[j];
    delete [] list;
    cout << "******************" << endl;
}

void LinkedList::print(char * name)
{
    cout << "Messages for " << name << endl;
    Node * current = nullptr;
    if(head)
        current = head;
    while(current)
    {   
        if(!strcmp(current->data->getRecipient(), name))
        {
            cout << "  " << current->data->getId() << endl;
        }
        current = current->next;
    }
}