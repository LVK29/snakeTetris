Dev C++: http://www.mediafire.com/download/jvca73gqgg0l783/Setup_DEVC%2B%2B+5.4.1.rar

Glutming: http://chortle.ccsu.edu/Bloodshed/glutming.zip

First install Dev C++ with all default settings..Just press Next and continue till end.

After installation place the files(glutming folder) in the folders specified:

glut.h: C:\Program Files (x86)\Dev-Cpp\MinGW32\include\GL

libglut32.a: C:\Program Files (x86)\Dev-Cpp\MinGW32\lib

glut32.dll: C:\Windows\SysWOW64

After this open Dev C++ and follow the steps:

Tools->Compiler Options->Compiler

Tick "Add the following commands when calling the compiler"

And paste this in the box following it: -lglu32 -lglut32 -lopengl32

Press OK