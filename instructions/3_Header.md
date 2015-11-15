Header
======

Header files are used to separate the interface from its implementation. They contain declarations of methods, variables and types. Usually header files don't have implementation code.

The code compiles, even if there is no implementation available. This is very useful for software development. All known functionality is defined by an interface respectively a header file at the beginning of a project. Each programmer can now implement an interface step by step.


Example: Calculator
-------------------

Start with `3_header/31_header`:

* `calculator.h` defines the interface of the calculator
* `calculator.c` implements the calculator interface
* `main.c` uses the calculator

`calculator.h` is the interface of the calculator and can be used by everyone who needs some math.
`main.c` can use the calculator with the help of: `#include "calculator.h"`:

    $ gcc -c main.c
    $ gcc -o main main.c

The code is compiled without problems, i.e. `main.o` is generated (What is `*.o`? See lesson 4.). But the executable can not be generated, because the compiler is missing the implementation. The implementation code must be provided to the compiler:

    $ gcc -o main main.c calculator.c
    $ ./main


Example: Calculator Conflicts
-----------------------------

Header files can raise include errors as well, e.g. `3_header/32_include_error`:

* `algorithm.h` defines the interface of the algorithm and uses a struct of calculator
* `algorithm.c` implements the algorithm interface
* `calculator.h` defines the interface of a new calculator
* `calculator.c` implements the calculator interface
* `main.c` uses the algorithm and calculator

The algorithm code uses some code from calculator and therefore `calculator.h` is included.
The compiler complains about a redefinition and conflicting types:

    $ gcc -c calculator.c
    $ gcc -c algorithm.c
    $ gcc -c main.c


Example: Calculator & Algorithm
-------------------------------

The problems can be solved by using a include guard, e.g. `3_header/33_include_guard`.
This example contains the same code like in 3.2 except that all header files have a include guard.

    $ gcc -c calculator.c
    $ gcc -c algorithm.c
    $ gcc -c main.c
    $ gcc -o main calculator.o algorithm.o main.o
