#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
    private:
        int id;
        char *name;
    public:
        Message(int idnum, char* r);
        Message(const Message& obj);
        ~Message();       
        int getId();                       
        char* getRecipient();                
};

#endif