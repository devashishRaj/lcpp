// The number of bits a data type uses is called its width. A wider data type is one that uses more
// bits, and a narrower data type is one that uses less bits.
#include <iostream>

void printDouble(double d) {
    std::cout << d << '\n';
}
void printInt(int x) {
    std::cout << x << '\n';
}

/*
     A numeric promotion is the type conversion of certain narrower numeric types (such as a char)
   to certain wider numeric types (typically int or double) that can be processed efficiently and is
   less likely to have a result that overflows.
*/
int main() {

    // NOTE:All numeric promotions are value-preserving

    // Floating point promotions
    printDouble(5.0);  // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double

    // Integral promotions:Assuming an 8 bit byte and an int size of 4 bytes or larger (which is
    // typical these days), the above basically means that bool, char, signed char, unsigned char,
    // signed short, and unsigned short all get promoted to int.
    // NOTE:it does not necessarily preserve the signedness (signed/unsigned) of the type.
    printInt(2);
    short s{3};     // there is no short literal suffix, so we'll use a variable for this one
    printInt(s);    // numeric promotion of short to int
    printInt('a');  // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int

    // Not all widening conversions are numeric promotions , there are five numeric conversion:
    // NOTE:brace initialization strictly disallows some types of numeric conversions
    // Converting an integral type to any other integral type (excluding integral promotions):
    short s2 = 3;       // convert int to short
    long l = 3;         // convert int to long
    char ch = s;        // convert short to char
    unsigned int u = 3; // convert int to unsigned int
    // Converting a floating point type to any other floating point type (excluding floating point
    // promotions):
    float f = 3.0;        // convert double to float
    long double ld = 3.0; // convert double to long double
    // Converting a floating point type to any integral type:
    int i = 3.5; // convert double to int
    // Converting an integral type to any floating point type:
    double d = 3; // convert int to double
    // Converting an integral type or a floating point type to a bool:
    bool b1 = 3;   // convert int to bool
    bool b2 = 3.0; // convert double to bool

    // narrowing conversion is a potentially unsafe numeric conversion where the destination type
    // may not be able to hold all the values of the source type. From wider width to narrower
    // width.
    // BestPractice:If you need to perform a narrowing conversion, use static_cast to convert it
    // into an explicit conversion. Brace initialization disallows narrowing conversions

    // arithmetic conversion rules
    // ranked list of types
    /*
        long double (highest rank)
        double
        float
        long long
        long
        int (lowest rank)

    If one operand is an integral type and the other a floating point type, the integral operand is
    converted to the type of the floating point operand (no integral promotion takes place).
    the operand with lower rank is converted to the type of the operand with higher rank.
    */
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n'; // show us the type of i + d
    std::cout << typeid(5u - 10).name() << ' ' << 5u - 10
              << '\n'; // 5u means treat 5 as an unsigned integer

    // Explicit type conversion (casting) and static_cast
    // 5 different types of casts: C-style casts, static casts, const casts, dynamic casts, and
    // reinterpret casts. The latter four are sometimes referred to as named casts.

    // C-style casts
    int x{10};
    int y{4};
    double d2{(double)x / y}; // convert x to a double so we get floating point division
    std::cout << d2 << '\n';  // prints 2.5
    // BestPractice:
    // C-style casts are at risk for being inadvertently misused and not producing the
    //  expected behavior. Avoid using C-style casts.

    // static_cast: it provides compile-time type checking, making it harder to
    // make an inadvertent error. static cast x to a double so we get floating point division
    double d3{static_cast<double>(x) / y};
    std::cout << d3 << '\n'; // prints 2.5

    return 0;
}