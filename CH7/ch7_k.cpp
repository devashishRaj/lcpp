#include <iostream>

namespace V1 // declare a normal namespace named V1
{
    void doSomething() {
        std::cout << "V1\n";
    }
} // namespace V1
// An inline namespace is a namespace that is typically used to version content. Much like an
// unnamed namespace, anything declared inside an inline namespace is considered part of the parent
// namespace. However, unlike unnamed namespaces, inline namespaces don’t affect linkage.
inline namespace V2 // declare an inline namespace named V2
{
    // All content declared in an unnamed namespace is treated as if it is part of the parent
    // namespace.

    // all identifiers inside an unnamed namespace are treated as if they have internal
    // linkage, which means that the content of an unnamed namespace can’t be seen outside of the
    // file in which the unnamed namespace is defined.
    namespace // unnamed namespace
    {
        void doSomething() // has internal linkage
        {
            std::cout << "V2\n";
        }

    } // namespace
} // namespace V2

int main() {
    V1::doSomething(); // calls the V1 version of doSomething()
    V2::doSomething(); // calls the V2 version of doSomething()

    // all callers to doSomething() will get the v2 version by default
    ::doSomething(); // calls the inline version of doSomething() (which is V2)

    return 0;
}