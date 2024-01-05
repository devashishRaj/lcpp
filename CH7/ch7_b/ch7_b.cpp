#include "add.h"    // for BasicMath::add()
#include "circle.h" // for BasicMath::pi
#include "growth.h" // for BasicMath::e
#include <iostream>

void print() // this print() lives in the global namespace
{
    std::cout << " there\n";
}

namespace Foo // define a namespace named Foo
{
    // This doSomething() belongs to namespace Foo
    int doSomething(int x, int y) {
        return x + y;
    }
    void print() // this print() lives in the Foo namespace
    {
        std::cout << "Hello";
    }
    void printHelloThere() {
        print();   // calls print() in Foo namespace
        ::print(); // calls print() in global namespace
    }
} // namespace Foo

namespace Goo // define a namespace named Goo
{
    // This doSomething() belongs to namespace Goo
    int doSomething(int x, int y) {
        return x - y;
    }
} // namespace Goo

namespace Foo::Goo // Goo is a namespace inside the Foo namespace (C++17 style)
{
    int add(int x, int y) {
        return x + y;
    }
} // namespace Foo::Goo
namespace V2 {
    int add(int x, int y) {
        return x + y;
    }
} // namespace V2

int main() {
    // User-defined namespaces and the scope resolution
    // a naming collision occurs when two identical identifiers are introduced into the same scope
    // Namespaces that you create in your own programs are casually called user-defined namespaces
    // (though it would be more accurate to call them program-defined namespaces).
    std::cout << Foo::doSomething(4, 3)
              << '\n'; // use the doSomething() that exists in namespace Foo
    std::cout << Goo::doSomething(4, 3)
              << '\n'; // use the doSomething() that exists in namespace Goo

    // Using the scope resolution operator with no name prefix
    Foo::print(); // call print() in Foo namespace
    ::print();    // call print() in global namespace (same as just calling print() in this case)

    // Identifier resolution from within a namespace
    /*
    In the below example, print() is called with no scope resolution provided. Because this use of
    print() is inside the Foo namespace, the compiler will first see if a declaration for
    Foo::print() can be found. Since one exists, Foo::print() is called.

    If Foo::print() had not been found, the compiler would have checked the containing namespace (in
    this case, the global namespace) to see if it could match a print() there.

    Note that we also make use of the scope resolution operator with no namespace (::print()) to
    explicitly call the global version of print().
    */
    Foo::printHelloThere();

    // Forward declaration of content in namespaces
    std::cout << BasicMath::add(4, 3) << '\n';
    // Multiple namespace blocks are allowed
    std::cout << BasicMath::pi << '\n';
    std::cout << BasicMath::e << '\n';

    // Nested namespaces
    std::cout << Foo::Goo::add(1, 2) << '\n';
    // Namespace aliases
    namespace Active = Foo::Goo;            // active now refers to Foo::Goo
    std::cout << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()
    // One nice advantage of namespace aliases: If you ever want to move the functionality within
    // Foo::Goo to a different place, you can just update the Active alias to reflect the new
    // destination
    // namespace Active = V2; // active now refers to V2
    std::cout << Active::add(1, 2) << '\n'; // We don't have to change this

    // When you should use namespaces
    //  namespaces can be used to separate application-specific code from code that might be
    //  reusable later
    // NOTE:When you write a library or code that you want to distribute to others, always place
    // your code inside a namespace.
    return 0;
}

// Warning:Do not add custom functionality to the std namespace.

// BestPractice:
/*
    Some reasons to prefer namespace names starting with a capital letter:

    - It is convention to name program-defined types starting with a capital letter. Using the same
   convention for program-defined namespaces is consistent (especially when using a qualified name
   such as Foo::x, where Foo could be a namespace or a class type).

    - It helps prevent naming collisions with other system-provided or library-provided lower-cased
   names.

    - The C++20 standards document uses this style.
    - The C++ Core guidelines document uses this style.
*/