#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>

class Replace {
    public:
        Replace();
        ~Replace();
        void replace(std::string filename, std::string s1, std::string s2);
};

void args_handling(char **av, std::string &filename, std::string &s1, std::string &s2);

#endif