#include "../inc/MutantStack.hpp"
#include <list>

int main() {

    {
        MutantStack<int> mstack;
        mstack.testStack();
    }
    std::cout << "\n\n----------------------------------------\n\n" << std::endl;
    std::cout << "**MutantStack**\n" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "\n\n----------------------------------------\n\n" << std::endl;
    std::cout << "**List**\n" << std::endl;
    {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        //[...]
        lst.push_back(0);
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::list<int> s(lst);
        (void)s; // To avoid unused variable warning
    }
    return 0;
}