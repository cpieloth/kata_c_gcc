Preprocessor: Comments, Macros & Defines
========================================

The preprocessor is executed before compiling and produces new C source code. Preprocessor output is comparable with
ordinary C code. Simplified, a text replacement with a bit of logic is done:

* Removing comments (/* multi-line comment */, // single-line comment),
* Inserting code from other files (#include),
* Replacing symbolic constants (#define)
* Interpreting macros and conditions (#define, #ifdef, #ifndef, #endif)


Macro / define
--------------

The directive

      #define
      
can be used for (1) a symbolic constant or (2) a macro, e.g.:

(1)   #define PI 3.14
(2)   #define MIN(x,y) ((x<y) ? x : y)

After preprocessing, every occurrence of PI in the source code is replaced by 3.14 and MIN(x,y) by ((x<y) ? x : y). 
Attention, it is just an replacement: MIN("3.14", 2.72) will be ("3.14"<2.72) ? "3.14" : 2.72
In the most cases, this is not what you want ...


#ifdef, #ifndef, #endif
-----------------------

With the directives

   #ifdef, #ifndef, #endif
   
you can check wether a condition is true or a symbolic constant is set. This can be used to skip lines of code, e.g.:

   #ifndef NDEBUG
   printf("very long debug output");
   #endif


Example
-------

The following command generates the preprocessor output for preprocessor.c and saves it in preprocessor.cpp.c

   $ gcc -E preprocessor.c > preprocessor.cpp.c

Now, have a look at

   src/1_preprocessor/preprocessor.c
   
The source code has some macros, defines and comments. Depending on NDEBUG we get some special debug output. Line 34 is 
changed to

   int var = 42;
   
and the comments will be removed.

To generate the preprocessor output execute these commands:

   $ gcc -E preprocessor.c > preprocessor1.cpp.c
   $ gcc -DNDEBUG -E preprocessor.c > preprocessor2.cpp.c
   
and compare the files preprocessor.c, preprocessor1.cpp.c and preprocessor2.cpp.c. But do not mind the first ~1.895 
lines, these are some inserted code from stdlib.h and stdio.h.
You can use meld for comparison:

   $ meld preprocessor.c preprocessor1.cpp.c
   $ meld preprocessor.c preprocessor2.cpp.c
   
After comparing the code, compile, link and run it:

   $ gcc -o preprocessor1 preprocessor1.cpp.c
   $ ./preprocessor1
   
   $ gcc -o preprocessor2 preprocessor2.cpp.c
   $ ./preprocessor2
   
What is the difference?
