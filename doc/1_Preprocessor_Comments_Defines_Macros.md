1. Preprocessor: Comments, Macros & Defines
===========================================

The preprocessor is executed before compiling and produces new C source code. Preprocessor output is comparable with ordinary C code. Simplified, a text replacement with a bit of logic is done:

* Removing comments:`/* multi-line comment */`, `// single-line comment`,
* Inserting code from other files: `#include <stdlib.h>`,
* Replacing symbolic constants: `#define EPS 0.0001`
* Interpreting macros and conditions: `#define, #ifdef, #ifndef, #endif`


Macro / define
--------------

The directive

      #define

can be used for:

1. a symbolic constant: `#define PI 3.14` or
2. a macro: `#define MIN(x,y) ((x<y) ? x : y)`

After preprocessing, every occurrence of `PI` in the source code is replaced by `3.14` and `MIN(x,y)` by `((x<y) ? x : y)`.

Attention, it is just a string replacement: `MIN("3.14", 2.72)` becomes `("3.14"<2.72) ? "3.14" : 2.72`
In the most cases, this is not what you want ...


ifdef, ifndef, endif
-----------------------

With the directives

    #ifdef
    #ifndef
    #endif

you can check whether a condition is true or a symbolic constant is set. This can be used to skip lines of code, e.g.:

    #ifndef NDEBUG
    printf("very long debug output");
    #endif


Example 1: Preprocessor
-----------------------

The following command generates the preprocessor output for `original.c` and saves it in `preprocessed.pp.c`

    $ gcc -E original.c > preprocessed.pp.c

Now, have a look at:

    src/1_preprocessor/preprocessor.c

The source code has some macros, defines and comments. Depending on `NDEBUG` we get some special debug output. Line 34 is
changed to

    int var = 42;

and the comments will be removed.

To generate the preprocessor output execute these commands:

    $ gcc -E preprocessor.c > preprocessor1.pp.c
    $ gcc -DNDEBUG -E preprocessor.c > preprocessor2.pp.c

and compare the files `preprocessor.c`, `preprocessor1.pp.c` and `preprocessor2.pp.c`. But do not mind the first ~1.895 lines, these are some inserted code from stdlib.h and stdio.h.
You can use meld for comparison:

    $ meld preprocessor.c preprocessor1.pp.c
    $ meld preprocessor.c preprocessor2.pp.c

After comparing the code, compile, link and run it:

    $ gcc -o preprocessor1 preprocessor1.pp.c
    $ ./preprocessor1

    $ gcc -o preprocessor2 preprocessor2.pp.c
    $ ./preprocessor2

What is the difference?
