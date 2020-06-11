#ifndef CLOCK_H
#define CLOCK_H

class clockType
{
public:
    clockType();
    clockType(int h,int m,int s);
    void setTime(int h,int m,int s);
    void getTime(int& h,int& m,int& s);
    void printTime() const;
    ~clockType();

private:
    int hr;
    int min;
    int sec;
};

#endif
