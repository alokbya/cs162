#ifndef PERSON_H
#define PERSON_H

class person
{
private:
    char* m_name;
    int m_yearBorn;

public:
    person(const char* name,const int yearBorn);
    person(const person& other);
    ~person();
    person& operator=(const person& other);
    void print();
};

#endif
