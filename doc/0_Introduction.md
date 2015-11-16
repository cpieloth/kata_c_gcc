Introduction
============

This tutorial is for people with some basic knowledge in C or even any other procedural programming language. The main part illustrates how a C toolchain (GNU C Compiler & Linker) compiles source code and how you can use this to structure your code. This is not an introduction to C programming e.g. "What are loops?".

The tutorial is divided into five successive parts and relies on the code. The code examples are very small and leave space for own experiments. It is recommended to follow the given order and it is mandatory to read, understand and run the code.

It is recommended to use an GNU/Linux instead of Windows. The tutorial was created and tested with Linux Ubuntu 14.04 and gcc 4.8.2. At least, you need the following software:

* GNU C Compiler (gcc)
* Text Editor (e.g. Atom, gedit, vim) or an IDE (e.g. Eclipse CDT)
* Optional:
 * Diff/Merge Tool e.g. Meld (meld)
 * GNU Make (make)


What is a compiler?
-------------------

In short, a compiler transforms high-level source code (e.g. C, Java) to low-level code (byte code, assembler code or machine code). For distinction between source code and machine code, source code as it is, can't be executed by a computer.

The advantages of high-level source code compared to low-level code are: easier to read and write for a developer, faster development, modularization, hardware abstraction and more. Of course, hardware and system optimization is limited.


Process of compilation
----------------------

C code passes through different stages during "compilation". The process of compilation is as follows:

1. **Preprocessing code** - removes comments, replacs includes, defines and marcos
2. **Checking syntax** - checks for missing semicolons, correct braces and more
3. **Compiling** - produces object code respectively machine code
4. **Linking** - combines object code to an executable application or a library
