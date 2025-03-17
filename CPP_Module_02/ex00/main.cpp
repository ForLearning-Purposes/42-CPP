#include "Fixed.hpp"
#include <iostream>


int main() {
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

return 0;
}

/*
INFO:
    -   A fixed-point number stores a real number as an integer with a fixed number of fractional bits.
    -   Orthodox Canonical Form
    -   operator= (copy assignment operator) is a special function used for copying an
        object and assigning it to another (already existing) object of the same type/class.
        -   if we don't define operator=, the compiler will generate a default one for us.
            which means it's goind to perform a shallow copy of the object. But we need to
            perform a deep copy of the object because if we had a pointer in the object, the
            default operator= would copy the address of the pointer, not the value it points to.
            which can lead to a double delete/free problem.
    -   copy constrictur is constructor and is used in creating new oobject by copying the
        values of another aleady existing object. Performing a deep copy of the object.
    -   operator is a special keyword, not just a function name.
        It allows defining how operators work for user-defined types.
        Without operator, you cannot overload operators.
        It improves readability, consistency, and integration with C++ features.
    -   Static means these functions belong to the class rather than an instance.
    -   Overloading means defining multiple functions with the same name but different parameter lists.
        In this case, there are two versions of min and max (see in the Fixed.hpp file).
*/