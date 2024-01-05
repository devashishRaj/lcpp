// https://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/
//  explore use cases of internal and external linkage

/*
What’s the difference between a variable’s scope, duration, and linkage? What kind of scope,
duration, and linkage do global variables have?


Scope determines where a variable is accessible. Duration determines when a variable is created and
destroyed. Linkage determines whether the variable can be exported to another file or not.

Global variables have global scope (a.k.a. file scope), which means they can be accessed from the
point of declaration to the end of the file in which they are declared.

Global variables have static duration, which means they are created when the program is started, and
destroyed when it ends.

Global variables can have either internal or external linkage, via the static and extern keywords
respectively.
*/