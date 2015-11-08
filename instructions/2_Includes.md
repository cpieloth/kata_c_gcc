Includes
========

`#include` enables the re-use of code. This statement includes code from a source or header files into a file. The include statement is processed by the preprocessor.

There are two notations:

1. `#include <FILE>`: Is used to include external code, e.g. standard C library.
2. `#include "FILE"`: Is usually used to include project internal  code.

Example: Simple Include
-----------------------

At the beginning have a look at `2_include/21_include`:

* `calculator_a.c` defines a function `add()`
* `calculator_b.c` also defines a function `add()`
* `main_a.c` includes `calculator_a.c`
* `main_ab.c` includes `calculator_a.c` and `calculator_b.c`

Let's check the output of the preprocessor:

    $ gcc -E main_a.c > main_a.pp.c
    $ meld main_a.c main_a.pp.c

    $ gcc -E main_ab.c > main_ab.pp.c
    $ meld main_ab.c main_ab.pp.c

The preprocessor inserts `calculator_a.c` into `main_a.c`. Unsurprisingly the preprocessor inserts `calculator_a.c` and `calculator_b.c` into `main_ab.c`.

Compilation and execution of `main_a.c`/`main_a.pp.c` is successful:

    $ gcc -o main_a main_a.c
    $ gcc -o main_a_pp main_a.pp.c
    $ ./main
    $ ./main_a_pp

Including more than one file can produces errors. Let's try to compile `main_ab.c`/`main_ab.pp.c`:

    $ gcc -o main_ab main_ab.c
    $ gcc -o main_ab_pp main_ab.pp.c

The compiler throws a error: _redefinition of ‘add’_. The compiler found two `add()` functions and can not decide which one should be used.


Example: Include Guard
----------------------

The redefinition problem can be solved by using macros and is mainly used to prevent duplicated includes of header files.

Have a look at `2_include/22_include_guard`:

* `calculator_a.c` defines a function `add()`
* `calculator_b.c` also defines a function `add()`
* `main_ab.c` includes `calculator_a.c` and `calculator_b.c`

There is only one change in the code. `add()` is surrounded by some macros:

    #ifndef _ADD_
    #define _ADD_

    int add(int a, int b);

    #endif  // _ADD_

The first include, `calculator_a.c`, in `main_ab.c` sets the define `_ADD_`. The second include, `calculator_b.c`, checks if a definition of `_ADD_` already exists. If `_ADD_` is found everything between `#ifndef _ADD_` and `#endif` is skipped:

    $ gcc -E main_ab.c > main_ab.pp.c
    $ meld main_ab.c main_ab.pp.c

Using this include guard the compilation is successful:

    $ gcc -o main_ab main_ab.c
    $ ./main_ab

Finally it has to be said, that including source files is a bad practice and header files should be used instead.
