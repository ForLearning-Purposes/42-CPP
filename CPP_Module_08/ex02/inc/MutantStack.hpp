#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

/*
typedef typename SomeType::NestedType AliasName;
 ^ 1. typename tells the compiler: “SomeType::NestedType
      is a type, not a static variable or method.”
   2. typedef creates an alias (a nickname) for that type.
___________________________________________________________
    - Why Do We Need typename?
    When using template classes, the compiler can’t always
    know whether something like SomeType::NestedType is a
    type or something else — until the template is
    instantiated.
    So typename tells the compiler
    “trust me, this is a type.”

    Without typename, you'd get a compile error.
*/

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack<T>& other);
        MutantStack<T>& operator=(const MutantStack<T>& other);
        virtual ~MutantStack();

        //_____________________________________________________________________

        typedef typename std::stack<T>::container_type::iterator        iterator;
        typedef typename std::stack<T>::container_type::const_iterator  const_iterator;

        //_____________________________________________________________________

        iterator begin(void)/*  {
            return (this->c.begin());
        }// */;
        iterator end(void) /* {
            return (this->c.end());
        }// */;
        const_iterator c_begin(void) const/*  {
            return (this->c.begin());
        }// */;
        const_iterator c_end(void) const /* {
            return (this->c.end());
        }// */;

        //_____________________________________________________________________

        void testStack() const;
};

#include "../template/MutantStack.tpp"

#endif