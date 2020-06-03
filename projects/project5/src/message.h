#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
    private:
        int id;
        char *name;
    public:
        Message(int idnum, char* r);    // overloaded constructor
        Message(const Message& obj);    // copy constructor
        ~Message();                     // destructor
        int getId();                    // return member id (int)
        char* getRecipient();           // return member name (char*)
};

#endif