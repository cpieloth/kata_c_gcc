Developer Guidelines for C Projects
===================================

Programming Style, Wikipedia:

> It is often claimed that following a particular programming style *will help programmers to read and understand source code* conforming to the style, and help to *avoid introducing errors*.

Code Format
-----------

A consistent code format reduces the diff size between commits, whereby the changeset is reduced to code changes only. Furthermore it is required for development on different systems, i.e. Unix and Windows.

* Encoding: UTF-8
* Line Ending: Unix `\n`
* Line Length: 120
* Indent Brace Style: Allman/BSD style
* Indent Style: Spaces
* Indent Size: 4
* CamelCase or snake_case: snake_case


Coding Guidelines
-----------------

Coding guidelines should improve readability/consistency, compatibility and code quality.
Furthermore it is a collection of project related best practices.

### Functions: Use _self_ as "this" Pointer

For object-oriented class methods the this-pointer must be named _self_ and NOT _this_.

*Example:*

    struct set;
    bool set_add(struct set* self, void* data);

*Pros:*

* Compatibility with C&plus;&plus; keyword _this_, if using C code in C&plus;&plus;
* Consistent naming improves readability


### Functions: Parameter Order

Output parameters of a method must be placed before input parameters.
For oo-like methods the self pointer is the first parameter.

*Example:*

    struct set my_set;
    set_to_array(&my_set, &array, array_len);

    size_t read_socket(void* out_buf, size_t len, int sd);
    size_t read_socket_timeout(void* out_buf, size_t len, int sd, size_t timeout_ms);

*Pros:*

* New input parameter "can be appended"
* Common for C++, which supports default parameters
* Consistent API


### Functions: Private Methods

Use `static` keyword and an underscore for local/private functions & variables.

*Example:*

    static void _foo();
    static int _bar;

*Pros:*

* principle of information hiding
* restrict access
* readability & consistency


### Includes

Some rules for includes:

* include what you use
* include order by groups and alphabetical:
 1. C library
 2. system header
 3. external dependencies includes
 4. project includes
* include notation:
 * angle brackets for external includes, e.g. `#include <stdio.h>`
 * double quotes for project includes, e.g. `#include "foo.h"`
* comment uncommon include, e.g. `#include <check.h> // functions for unit testing`


*Example:*

    #include <stdio.h>
    #include <string.h>

    #include <sys/queue.h>
    #include <sys/syslog.h>

    #include "foo/bar.h"
    #include "bar.h"


### for-loop

Declare counter variable of for-loops in the _init_clause_ (supported since C99).

*Example:*

    for(size_t i = 0; i < n_array; ++i)
    {
        sum += array[i];
    }

*Pros:*

* prevents accidental access
* readability


### Enumerations

Use enum name as prefix for enumerator names.

*Example:*

    enum IO_MODE
    {
        IO_MODE_READ, IO_MODE_WRITE, IO_MODE_APPEND, ...
    }

*Pros:*

* reduces naming conflicts
* better auto-completion

*Cons:*

* long enumerator names


### Prefer Types over Documentation

Data types should be preferred over variable names/documentation when designing interface/API.

*Example:*

    // bad: int set_is_empty(const struct set *self);
    // good:
    bool set_is_empty(const struct set *self);

    // bad: size_t write(FILE* fd, const void *data, int nbytes, int mode);
    // good:
    enum IO_MODE
    {
        IO_MODE_APPEND, ...
    }

    size_t write(FILE* fd, const void *data, int nbytes, enum IO_MODE mode);

*Pros:*

* accidentally swapped parameters raises compiler errors
* reduces bugs produced by wrong assumptions, e.g. <0, 0 or >0 on error?


### Common Names, Abbreviation & Prefixes

Agree on a set common names, abbreviation and prefixes.

*Example:*

* `ctx, cls, rc, len, mgr, utl, ptr, cb, ...`

*Pros:*

* readability & consistency

### Misc

* use const-correctness
* define use of typedefs


Documentation & Code Comments
-----------------------------

### General Documentation

Put developer documentation into the project's SCM (e.g. git). Use simple markup language, e.g. Markdown or AsciiDoc.


### API Documentation

Use [Doxygen](http://www.doxygen.org) with the following notation for API documentation:

    struct user
    {
        unsigned int id; //!< The user ID.
    }

    /**
     * Adds a user to something.
     *
     * @user The user to add.
     * @return True on success.
     */
    bool user_add(struct user* user);


### Code Comments

Use backslash notation for single-line and multi-line comments:

    // Initialization:
    struct user my_user;
    my_user.id = 1;

    // Processing:
    // 1. Add user to database
    // 2. Print user information
    // 3. ...
    user_add(&my_user);
    user_print(&my_user);

Task Tags:

* must contain a related ticket number or a developer name
* developer name can be used for inquiries, it does not indicates who should solve the issue
* `// TODO`, `// FIXME`, `// NOTE`
* Examples:
```
// TODO(cpieloth): Add log message.
// FIXME(#42): Handle rc to prevent seg fault.
// NOTE(cpieloth): The current algorithm has the following drawbacks: ...
```


Project File Structure
----------------------

A common and clear file structure for C projects:

    project/             # project root
    project/build        # build folder for compilation, artifacts and more
    project/cmake        # CMake files for build system
    project/doc          # documentation in a text document format, e.g. AsciiDoc or Markdown
    project/resources    # Resources, e.g. images, configs
    project/src          # source code
    project/tools        # useful tools/scripts, e.g. packaging, config files/generator for IDE


Tools
-----

Tools can enforce coding guidelines and support developers in their daily work:

* Auto Formatter & Code Templates functionality of IDEs (e.g. Eclipse, CLion)
* [Editorconfig](http://editorconfig.org) maintains consistent coding styles between different editors and IDEs
* [git autocrlf & whitespace](https://git-scm.com/book/tr/v2/Customizing-Git-Git-Configuration#Formatting-and-Whitespace) can check correct line endings and spacing
* [git hooks](https://git-scm.com/book/en/v2/Customizing-Git-Git-Hooks) can call scripts before a commit
* [cppcheck](http://cppcheck.sourceforge.net) for static code analysis
* [Lint](https://en.wikipedia.org/wiki/Lint_%28software%29) and their derivatives
* [AsciiDoc](http://asciidoc.org)
* [Markdown](https://daringfireball.net/projects/markdown)
* [Doxygen](http://www.doxygen.org)


Further Reading
---------------

* https://github.com/google/styleguide
* https://google-styleguide.googlecode.com/svn/trunk/cppguide.html
* http://www.misra-c.com
* https://en.wikipedia.org/wiki/Indent_style
* https://en.wikipedia.org/wiki/CamelCase
* https://en.wikipedia.org/wiki/Snake_case
* https://en.wikipedia.org/wiki/Const_%28computer_programming%29
