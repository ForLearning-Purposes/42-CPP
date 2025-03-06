#include <iostream>

/*
Write a program that contains:
• A string variable initialized to "HI THIS IS BRAIN".
• stringPTR: a pointer to the string.
• stringREF: a reference to the string.
Your program must print:
• The memory address of the string variable.
• The memory address held by stringPTR.
• The memory address held by stringREF.
And then:
• The value of the string variable.
• The value pointed to by stringPTR.
• The value pointed to by stringREF.
*/
int main (void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str; //Pointer to the string
    std::string &stringREF = str; //Reference to the string
    //Print memory addressess
    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    /*
    stringREF will have the same address as str.
    A reference (std::string&) is just another name (alias)
    for an existing variable—it does not occupy separate memory.
    */
    //Print values
    std::cout << "\nThe value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}

/*

The key difference between a pointer to a string (std::string*) and a reference to
a string (std::string&) is how they handle ownership, nullability, and reassignment.

__________________________________________________________________________________________
Feature 	std::string* stringPTR = &str;	    std::string& stringREF = str;
------------------------------------------------------------------------------------------
Definition	Stores the memory address of str.	Alias to str, does not store an address.

Dereferen-	*stringPTR gives access to the      Used directly like str.
cing            actual string.

Nulla-  	Can be nullptr                      Must always reference a valid string.
bility      (i.e., stringPTR = nullptr;).

Reassig-	Can point to another string 	    Cannot be changed to reference another string after initialization.
nment       (stringPTR = &anotherStr;).

Memory      Requires explicit dereferencing     Directly accesses str as if it's another name for it.
Access	    (*stringPTR).

*/