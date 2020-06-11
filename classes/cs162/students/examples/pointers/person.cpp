#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;

person::person(const char* name,const int yearBorn)
{
    m_name = new char[strlen(name)+1];
    strcpy(m_name,name);
    m_yearBorn = yearBorn;
}

person::person(const person& other)
{
    m_name = new char[strlen(other.m_name)+1];
    strcpy(m_name,other.m_name);
    m_yearBorn = other.m_yearBorn;
}

person::~person()
{
    cout << "in destructor for " << m_name << endl;
    delete [] m_name;
}

void person::print()
{
    cout << m_name << " was born in " << m_yearBorn << endl;
}

person& person::operator=(const person& other)
{
    delete [] m_name;

    m_name = new char[strlen(other.m_name)+1];
    strcpy(m_name,other.m_name);
    m_yearBorn = other.m_yearBorn;
}
