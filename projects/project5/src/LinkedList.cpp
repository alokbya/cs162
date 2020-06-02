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
    // create message object
    Message * m = new Message(id, name);
    Node * n = nullptr;         // instantiate new node
    n = new Node;               // allocate mem for new node
    n->data = m;                // set node.data pointer
    n->next =  head;
    head = n;
    cout << "Recieve: " << name << endl;
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
                    // cout << current->next->data->getId() - val << endl;
                    // cout << "Found node: " << current->next->data->getId() << endl;
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
        // tail->next = next;
        // cout << "Del_n: " << del_n << endl;//delete del;
        // cout << "Del_m: " << del_m << endl;//delete del;
        // cout << "Set to delete -> " << val << " : " << del_m->getId() << " <- Deleting" << endl;
        
        delete del_m;
        delete del_n;
    }

    return found;
}

void LinkedList::print()
{
    cout << "** All Messages **" << endl;
    Node * current = nullptr;
    if(head)
        current = head;
    while(current)
    {
        cout << "Message " << current->data->getId();
        cout << " " << current->data->getRecipient() << endl;
        current = current->next;
    }
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
            cout << current->data->getId() << endl;
        }
        else
        {
            // cout << current->data->getRecipient();
            // cout << " != " << name << " : ";
            // cout << strcmp(current->data->getRecipient(), name);
            // cout << endl;
        }
        // cout << " " << current->data->getId() << endl;
        current = current->next;
    }
}