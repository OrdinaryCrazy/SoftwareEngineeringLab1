#include "include/Core.h"
class CoreImplement:public Core
{
private:
    /* data */
public:
    int gen_chain_word(std::vector<std::string> &words, std::vector<std::string> &result, char head = 0, char tail = 0);
    int gen_chain_char(std::vector<std::string> &words, std::vector<std::string> &result, char head = 0, char tail = 0);
};

