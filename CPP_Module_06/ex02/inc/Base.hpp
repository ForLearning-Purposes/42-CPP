#ifndef BASE_HPP
#define BASE_HPP

//These four classes don’t have to be designed in the Orthodox
//Canonical Form.

//including the typeinfo header is forbidden

class Base {
    public:
        virtual ~Base();
};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif