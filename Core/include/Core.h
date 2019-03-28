class Core{
    // 对外发布的接口
    public:
        virtual int gen_chain_word(char* words[], int len, char* result, char head, char tail);
        virtual int gen_chain_char(char* words[], int len, char* result, char head, char tail);
        // TODO: -n interface
}