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
        void setId(int id);                 
        void setRecipient(char* r);         
        int getId();                       
        char* getRecipient();                
};

#endif