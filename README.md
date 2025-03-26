# 42-CPP
- Here is the documentatio about each module and things learned in each

---
### Module 00
- Namespaces, Classes, Member functions, Stdio stream, Initialization lists, Static, Const,...
    #### Namespaces
    - Namespaces – A mechanism for organizing code and preventing name conflicts. It allows defining groups of identifiers (functions, classes, variables) under a specific name.
    #### Classes
    - Classes – The fundamental building block of object-oriented programming in C++. A class defines data (members - variables) and functionality (methods - functions) that belong to an object.
    #### Member functions
    - Member Functions – Functions that are defined inside a class and have access to its data. They can be public, private, or protected.
    #### Stdio stream
    - Stdio Stream (Standard Input/Output Streams) – A set of classes from the <iostream> library that allow working with console and file input/output. Examples:
        - cin (console input)
        - cout (console output)
        - ifstream (reading from a file)
        - ofstream (writing to a file)
    #### Initialization lists
    - Initialization Lists – Used in constructors to initialize class members before the constructor body executes. Particularly useful for const and reference members.
    #### Static
    - Static – Can be used for variables and functions within a class. A static variable is shared among all objects of the class, and a static function can be called without instantiating an object.
    #### Const
    - Const – A keyword that indicates a variable, function, or pointer cannot be modified.
    ##### Notes
    - 
---
### Module 01
- Memory allocation, Pointers to members, References and Switch statements
    #### Memory allocation
    - Memory Allocation – The process of reserving memory for variables, objects, or data structures during program execution. It can be static (at compile time) or dynamic (at runtime using new and delete).
    #### Pointers to members
    - Pointers to Members – Special pointers that store the address of a class member (variable or function). They are used with ::*varName (for data members) and ::*funcName() (for member functions).
    #### References
    - References – Alternative names (aliases) for existing variables. They must be initialized when declared and cannot be changed to reference another variable.
    #### Switch statements
    - Switch Statements – A control flow statement that selects one of multiple possible execution paths based on an integer or character expression.
---
### Module 02
- Ad-hoc polymorphism, Operator overloading and the Orthodox Canonical class form
    #### Ad-hoc polymorphism
    - Ad-hoc Polymorphism – A form of polymorphism where functions or operators behave differently based on their arguments. It is achieved using function overloading and operator overloading.
        - Function overloading: Multiple functions with the same name but different parameters.
        - Operator overloading: Redefining how operators work for user-defined types.
    #### Operator overloading
    - Operator Overloading – A feature in C++ that allows redefining the behavior of operators (+, -, ==, etc.) for user-defined classes.
    #### the Orthodox Canonical class form
    - Orthodox Canonical Class Form (OCCF) – A set of four special member functions that a C++ class should implement for proper memory management and copy semantics. These are:

        - Default constructor: Initializes an object.
        - Copy constructor: Creates a copy of an existing object.
        - Copy assignment operator (operator=): Assigns one object to another.
        - Destructor: Cleans up resources.
---
### Module 03
- Inheritance
    #### Inheritance
    - Inheritance is an object-oriented programming concept that allows a class (child class) to inherit attributes and behaviors from another class (parent class). This promotes code reusability and hierarchical relationships between classes. Types of Inheritance:
        - Single Inheritance – A child class inherits from a single parent.
        - Multiple Inheritance – A child class inherits from more than one parent class.
        - Multilevel Inheritance – A class inherits from another class, which itself is inherited from another.
        - Hierarchical Inheritance – Multiple child classes inherit from the same parent.
        - Hybrid Inheritance – A combination of two or more types of inheritance, which can sometimes lead to the diamond problem (solved using virtual inheritance).
    - Access Specifiers in Inheritance
        - Public Inheritance (class Derived : public Base) → Keeps public and protected members as they are.
        - Protected Inheritance (class Derived : protected Base) → public and protected members become protected in the derived class.
        - Private Inheritance (class Derived : private Base) → public and protected members become private in the derived class.
    - Virtual Functions and Overriding
        - When a function is marked as virtual in a base class, it allows dynamic polymorphism, meaning the derived class can override it.
---
### Module 04
- Subtype Polymorphism, Abstract Classes, and Interfaces
    #### Subtype Polymorphism
    - Subtype polymorphism allows an object of a subclass to be treated as an object of its superclass while still maintaining its specific behavior. This enables dynamic method overriding and is commonly used in object-oriented programming (OOP).
    #### Abstract Classes
    - An abstract class is a class that cannot be instantiated directly, but is meant to be used as a base class for other classes. It serves as a blueprint for other classes, providing common functionality and enforcing that derived classes implement certain methods.
    #### Interfaces in OOP
    - An interface is a contract that defines a set of methods that a class must implement. It does not provide any implementation for these methods, only the method signatures (i.e., the method name, parameters, and return type). Classes that implement an interface must provide their own implementation for all of the interface's methods.
---
### Module 05
- Repetition and Exceptions
    #### Repetition
    - 
    #### Exceptions
    - 