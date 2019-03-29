#include "include/Core.h"
class CoreImplement:public Core
{
private:
    /* data */
public:
    CoreImplement(/* args */);
    ~CoreImplement();
    int gen_chain_word(char* words[], int len, char* result[], char head, char tail);
    int gen_chain_char(char* words[], int len, char* result[], char head, char tail);
};

