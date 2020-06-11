#include <iostream>
#include "clock.h"

void fancyPrint(const clockType& c)
{
    std::cout << "The time is: ";
    c.printTime();
}

int main()
{

    clockType myclock;
    clockType yourclock(8,7,6);

    fancyPrint(myclock);
    fancyPrint(yourclock);

    myclock.setTime(1,2,3);
    yourclock.setTime(4,5,6);

    fancyPrint(myclock);
    fancyPrint(yourclock);

    myclock = yourclock;

    fancyPrint(myclock);
    fancyPrint(yourclock);

    myclock.setTime(1,2,-9999);

    fancyPrint(myclock);

    clockType allClocks[10];

    return 0;
}
