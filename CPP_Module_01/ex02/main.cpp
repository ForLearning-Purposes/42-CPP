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
    std::string *stringPTR = &str; //Pointer to the string - by *stringPTR you can access the value of str, but we created a pointer to the string
    std::string &stringREF = str; //Reference to the string - by &stringREF you can access the value of str, but we created a reference of the string
    //Print memory addressess
    std::cout << "The memory address of the string variable: " << &str << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    //Print values
    std::cout << "\nThe value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}