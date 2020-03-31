Lab 1

======================================================================

The object of this lab is to give you experience compiling programs on the
command line using g++.

Step 0: As a part of setting up for this lab, you should have copied
readme.txt (this file) and hello.cpp in to your lab01 directory. The fact that
you're reading this file probably means that you did this. If you don't have
the hello.cpp file, copy it again from
~mike.noel/classes/cs162/students/lab01/.

Step 1: Compile the hello.cpp file using g++. The common way to do this is:

g++ -o myhello hello.cpp

Let me explain each part of that command line. The first item, "g++", is the
command. This it the Gnu C++ compiler. It is a free compiler available on
Linux, Windows, and macOS. This is the compiler we'll be using this term.

The second part, "-o myhello" is a flag to the compiler that says to create
output the resulting executable to the name "myhello". In Linux executable
files don't typically end in an extension (like .exe in Windows). If you omit
the "-o" option then the default output file will be created and that is
called "a.out". That is one exception to not using file extentions. Since
"a.out" is almost never the name that you want for your program, you should
always use "-o".

The final part, "hello.cpp", is the name of the file to compile.

Another way to compile is to include the "-g" flag. When you include "-g" that
compiles the program with debug information. We'll use that in the next lab.

Step 2: Run your program by typing "./myhello". You should see it print "Hello
world from linux!".

Step 3: Remove the executable by typing "rm myhello".

Step 4: Start learning a text editor.

There are three allowed text editors: emacs, vim, nano. My preference is emacs
but you are welcome to use any of them. There are numerous tutorials online to
learn any of those editors. I am not recommending any particular tutorial
since everyone has a different learning style and should find the tutorial
that works best for them.

Step 5: Edit hello.cpp

Once you have learned a text editor, use it to edit hello.cpp to have a custom
message then recompile the program and run it again. You should see your new
message.

Step 6: Create a tar file with the hello.cpp program in it. You create a tar
file like this:

tar cvf lab01.tar hello.cpp

After running this command you will see lab01.tar in your directory.

Step 7: Use turnin to submit lab01.tar. The "turnin" command is a command to
turn in programs and lab assignments. The instructions for "turnin" are in
~mike.noel/classes/all/turnin.txt. Use "less
~mike.noel/classes/all/turnin.txt" to view the instructions. Remember, in
"less", the space bar will page down and the letter "q" will quit.

Follow the instructions to setup turnin and then turnin lab01.tar.

