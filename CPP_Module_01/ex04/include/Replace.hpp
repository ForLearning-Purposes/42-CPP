#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>

class Replace {
    public:
        Replace();
        ~Replace();
        void replace(std::string filename, std::string search, std::string replace, std::string content);
};

void                args_handling(char **av);
const std::string   content(std::string filename);

#endif