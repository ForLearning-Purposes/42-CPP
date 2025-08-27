#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

class DataParsing {
    public:
        void parseArgs(int ac, char **av);
        bool isPoitive(const std::string& s);
    private:
        std::vector<int> vec;
        std::deque<int> dq;
};

bool DataParsing::isPoitive(const std::string& s) {
    if (s.empty()) return false;
    for (int i = 0; s[i] != '\0'; i++)
        if (!isdigit(s[i])) return false;
    return true;
}

void DataParsing::parseArgs(int ac, char **av){
    for (int i = 1; i < ac; i++){
        std::string str = av[i];
        if (!isPoitive(av[i])){
            std::cout << "Error" << std::endl;
            exit(1);
        }
    }
}

int main(int ac, char **av) {
    (void)av;
    if (ac < 2) {
        std::cerr << "ERROR\nUsage: ./prog num1 num2 num3 ..." << std::endl;
        return 1;
    }
    DataParsing pars;
    pars.parseArgs(ac, av);

    // std::vector<int> vec;
    // std::deque<int> dq;

    // for (int i = 0; i <= 10; i++) {
    //     vec.push_back(i);
    //     dq.push_back(i);
    // }

    // std::cout << "Vector:\t";
    // for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
    //     std::cout << *it;
    //     if (it != vec.end() - 1)
    //         std::cout << ", ";
    //     else
    //         std::cout << ".";
    // }
    // std::cout << std::endl;

    // std::cout << "Deque:\t";
    // for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); it++){
    //     std::cout << *it;
    //     if (it != dq.end() - 1)
    //         std::cout << ", ";
    //     else
    //         std::cout << ".";
    // }
    // std::cout << std::endl;
}