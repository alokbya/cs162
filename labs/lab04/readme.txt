Lab 04

======================================================================

Implement the three member functions specified in student.h. You need to fill
in the implementation in student.cpp:

  Student(const char initId[], double gpa)

    The above function will initialize a newly created student object with the
    passed in value

  bool isLessThanByID(const Student& aStudent)	

    The above function will compare the current student object with the passed
    in one by id.

  bool qualifyForHonor(double minGpaForHonor)	

    The above function will return true if the student's gpa is higher than
    "minGpaForHonor".

app.cpp is used to test your code. You need to fill in the blank to test the
above functions you create for Student class. You can build the app using the
make utility, which is supported by the file named makefile provided in the
directory.

For lab04 submission, bundle your source files together using tar then submit
the tar file using the turnin command. You can use this command to create a
tar file:

  tar cvf lab04.tar app.cpp student.cpp student.h



