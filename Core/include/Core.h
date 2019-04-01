#include <vector>
#include <string>
#include <set>

class Core{
    // 对外发布的接口
    public:
        virtual int gen_chain_word(std::vector<std::string> &words, std::vector<std::string> &result, char head = 0, char tail = 0){};
        virtual int gen_chain_char(std::vector<std::string> &words, std::vector<std::string> &result, char head = 0, char tail = 0){};
        virtual int all_chain_word(std::vector<std::string> &words, std::set<std::vector<std::string>> &result, int n, char head = 0, char tail = 0){};
        virtual std::vector<std::string> text_preprocess(std::string inputFile){};
        virtual std::vector<std::string> preprocessingData(std::string crudeData){};
};
