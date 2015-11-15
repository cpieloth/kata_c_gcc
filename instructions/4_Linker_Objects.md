Linker & Objects
================

Object code is the result of compiled source code, e.g.:

    $ gcc -c main.c

This produces an object file: `main.o`.
Object code is not executable. A linker produces an executable from one more object files, e.g.:

    $ gcc -o main main.o obj1.o obj2.o

Object files speed up the build process. Code that was not changed since the last compilation must not be re-compiled, instead the related object files can be used.

Furthermore, the combination of header files (interface), object files (implementation) and the linker enables to change/link the implementation at compile time, e.g. to use hardware acceleration on target architecture or use a Linux/Windows implementation.


Example: Calculator
-------------------

Have a look at `4_linker_objects`:

* `calculator.h` defines the interface of the calculator
* `calculator_basic.c` basic implementation of the calculator
* `calculator_std.c` implementation of the calculator using standard C operators
* `main.c` uses the calculator

`calculator_basic.c` implements the calculator by using basic loops. `calculator_std.c` uses the standard C operators +, -, / and %.
Without changing `main.c`, the implementation can be changed at compile time:

    $ # Compilation
    $ gcc -c main.c
    $ gcc -c calculator_basic.c
    $ gcc -c calculator_std.c

    $ # Linking
    $ gcc -o main_basic main.o calculator_basic.o
    $ gcc -o main_std main.o calculator_std.o

    $ # Execution
    $ ./main_basic
    $ ./main_std

You can see in the output which implementation is used.
If the implementation (`calculator_basic.o` or `calculator_std.o`) is missing, the linker throws an _undefined reference_ error:

    $ gcc -o main_basic main.o
    $ gcc -o main_basic main.c
