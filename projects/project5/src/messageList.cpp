// #include <iostream>
// #include <cstring>
// #include "messageList.h"

// using namespace std;

// MessageList::MessageList()
// {
//     head = nullptr;
//     // head->next = nullptr;
//     // head->m = NULL;
// }

// MessageList::~MessageList()
// {
//     Node * current = nullptr;
//     Node *next = nullptr;
//     if(head)
//         current = head;
//     while(current)
//     {
//         next = current->next;
//         delete current;
//         current = next;
//     }
//     // delete head;
// }

// bool MessageList::addNewMessage(Message &message)
// {
//     // adds node to beginning of list
//     // create a node
//     // cout << m->getRecipient() << " " << m->getId() << endl;

//     Node * n = new Node;
//     n->m = &message;
//     n->next = head;
//     head = n;
    
    
//     // head = n;
//     // if(head)
//     //     n->next = head;
//     // head = n;

//     // Node *newNode = nullptr;
//     // newNode = new Node;
//     // newNode->m = m;                     // set node data
//     // newNode->next = head;               // set link to head

//     // if(!head)                           // empty list
//     //     head = newNode;
//     // else
//     // {
//     //     newNode->next = head;
//     //     head->next = nullptr;
//     // }
//     // head = newNode;

//     // cout << "!Added " << m->getId() << " " << m->getRecipient() << endl;
//     return true;
// }

// bool MessageList::listMessages(char *r)
// {
//     cout << "Listing messages for: " << r << endl;
//     Node *current = nullptr;
//     if(head)
//         current = head;
//     while(current)
//     {
//         char* name = current->m->getRecipient();
//         if(strcmp(r, name) == 0)
//             cout << current->m->getId() << " ";
//         // cout << "fin." << endl;
//         current = current->next;
//     }
//     cout << endl;
//     return true;
// }

// void MessageList::listAllMessages()
// {
//     cout << "** All Messages **" << endl;
    
//     Node * current = nullptr;
//     if(head)
//         current = head;
//     while(current)
//     {
//         cout << current->m->getId() << endl;
//         current = current->next;
//     }

//     cout << "******************" << endl;
// }

// bool MessageList::deleteMessage(int id)
// {
//     // bool found = false;
//     // Node *toDelete = nullptr;
//     // Node *current = head;
//     // Node* trailCurrent = nullptr;

//     // while(current && !found)
//     // {
//     //     if(current->next->m->getId() == id)
//     //     {
//     //         found = true;
//     //         // *toDelete = *current->next;
//     //         trailCurrent = current;
//     //         current = current->next->next;
//     //         trailCurrent->next = current;
//     //     }
//     //     delete toDelete;
//     // }
//     return true;
// }