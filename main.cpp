// This is a Software Engineering Group Project
// Contributor: DaiLu, WangHaoyu, ZhangJingtun
// Last modified: 20190311 17:01
#include "Core/CoreImplement.h"
#include "Core/exception.h"
#include <iostream>
#include <vector> 
#include <string.h>
void usage(){
    std::string usage="Usage: Wordlist [arguments] <filename>\r\n\
Mandatory arguments:\r\n\
    -c: Output one word list with the most characters. \r\n\
    -w: Output one word list with the most words.\r\n\r\n\
Optional arguments:\r\n\
    -h <char>: Determine the head character of the word list.\r\n\
    -t <char>: Determine the tail character of the word list.\r\n\
    (Note: -h and -t can be used at the same time)\r\n\
    -n <num>: Output all word lists containing <num> words.\r\n\
    (Note: -n must be used with -w)\r\n";
    std::cout<<usage;
    exit(0);
}
int main (int argc, char*argv[]){

    bool mostChar = false;      //最多字母模式开关
    bool mostWord = false;      //最多单词模式开关
    bool fixedWordNum = false;  //确定单词数量模式开关
    bool fixedHead = false;     //确定开头字母模式开关
    bool fixedTail = false;     //确定结尾字母模式开关
    int wordNum;                //确定单词数量模式对应的单词数量
    std::string inputFile;      //数据文件名
    char head=0,tail=0;             //确定的开头字母和结尾字母

    if (argc<=2){
        std::cout<<"Too few arguments."<<std::endl;
        usage();
    }
    inputFile = std::string(argv[argc-1]);
    for(int i=1;i<argc-1;i++){
        if (strlen(argv[i])==2 && argv[i][0]=='-'){
            switch (argv[i][1]){
                case 'w':
                    mostWord = true;
                    break;
                case 'c':
                    mostChar = true;                   
                    break;
                case 'h':
                    fixedHead = true;
                    if (i+1<argc-1 && strlen(argv[i+1])==1){
                        head = argv[i + 1][0];
                        if ('A'<=head && head<='Z'){
                            head=head+32;
                        }
                        if (head<'a' || head>'z'){
                            std::cout<<"A character is needed after -h."<<std::endl;
                            usage();
                        }
                        i++;
                    }
                    else{
                        std::cout<<"A character is needed after -h."<<std::endl;
                        usage();
                    }                   
                    break;
                case 't':
                    fixedTail = true;
                    if (i+1<argc-1 && strlen(argv[i+1])==1){
                        tail = argv[i + 1][0];
                        if ('A'<=tail && tail<='Z'){
                            tail=tail+32;
                        }
                        if (tail<'a' || tail>'z'){
                            std::cout<<"A character is needed after -t."<<std::endl;
                            usage();
                        }
                        i++;
                    }
                    else{
                        std::cout<<"A character is needed after -t."<<std::endl;
                        usage();
                    }    
                    break;
                case 'n':
                    fixedWordNum = true;
                    try{
                        if (i+1>=argc-1) throw 0;
                        int n=strlen(argv[i+1]);
                        for (int j=0;j<n;j++){
                            if (argv[i+1][j]<'0' || argv[i+1][j]>'9')   throw 0;
                        }
                        wordNum = stoi(std::string(argv[i + 1]));
                        i++;
                        if (wordNum<=0) throw 0;
                    }
                    catch(...){
                        std::cout<<"A positive integer is needed after -n."<<std::endl;
                        usage();
                    }                                                    
                    break;
                default:
                    std::cout<< "Invalid option." <<std::endl;
                    usage();
                    break;
            }
        }
        else{
            std::cout<< "Invalid argument." <<std::endl;
            usage();
        }
    }
    
    if (mostChar==mostWord || (fixedWordNum &&  mostChar) ){
        std::cout<< "Wrong argument usage." <<std::endl;
        usage();
    }
    //处理命令行参数，拒绝所有非法的参数

    CoreImplement coreTest;
    std::vector<std::string> input;
    try{
        input = coreTest.text_preprocess(inputFile);
    }
    catch(expt::exception ex){
        std::cout<<ex.message<<std::endl;
        usage();
    }
    //从文件中读取并预处理输入文本，捕捉异常

    try{
        if (fixedWordNum){
            std::set<std::vector<std::string>> result;
            coreTest.all_chain_word(input,result,wordNum,head,tail);
        }
        else if (mostWord){
            std::vector<std::string> result;
            coreTest.gen_chain_word(input,result,head,tail);
        }
        else if (mostChar){
            std::vector<std::string> result;
            coreTest.gen_chain_char(input,result,head,tail);
        }
    }
    catch(expt::exception ex){
        std::cout<<ex.message<<std::endl;
        usage();
    }
    //根据模式开关调用对应的API，并捕捉异常

}
