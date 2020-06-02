#include <cstring>
#include <iostream>
using namespace std;
#define BUFF 256
#include "message.h"

Message::Message(int idnum, char* r)
{
    name = nullptr;
    id = idnum;
    setRecipient(r);
}

Message::Message(const Message& obj)                    // copy constructor
{
    // id = obj.id;
    // name = new char[BUFF];
    // for(int i = 0; i < static_cast<int>(strlen(obj.name)); i++)
    //     name[i] = obj.name[i];
    
}

Message::~Message()
{
    delete [] name;
}

void Message::setId(int id)
{
    this->id = id;
}

void Message::setRecipient(char *r)
{
    delete [] name;
    name = new char[BUFF];
    strcpy(name, r);
} 

int Message::getId()
{
    return id;
}

char* Message::getRecipient()
{
    return name;
}



