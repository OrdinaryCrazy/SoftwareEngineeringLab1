#include "CoreImplement.h"
#include "specifiedHeadOrTail.h"
#include "specifiedWordNumbers.h"
#include "defaultCase.h"
#include "exception.h"
#include <algorithm>
#include <setjmp.h>
#include <fstream>
// g++ -fno-rtti test.cpp ../CoreImplement.cpp 

int CoreImplement::gen_chain_word(std::vector<std::string> &words, std::vector<std::string> &result, char head, char tail)
{   
    def::longestList.clear();
    sHoT::resultPath.clear();
    if (words.size()==0){
        expt::exception ex;
        ex.location="gen_chain_word";
        ex.message="No element in words.";
        throw ex;
    }
    // 抛出words为空异常
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::tolower);
        for (int j=0; j<words[i].length(); j++){
            if (words[i][j]<'a' || words[i][j]>'z'){
                expt::exception ex;
                ex.location="gen_chain_word";
                ex.message="At least one element of words is illegal.";
                throw ex;
            }
        }
    }
    // 抛出words非法异常(含有非字母字符)
    head=tolower(head);
    tail=tolower(tail);
    if (head!=0 && (head<'a' || head>'z')){
        expt::exception ex;
        ex.location="gen_chain_word";
        ex.message="Illegal head.";
        throw ex;
    }
    if (tail!=0 && (tail<'a' || tail>'z')){
        expt::exception ex;
        ex.location="gen_chain_word";
        ex.message="Illegal tail.";
        throw ex;
    }
    // 抛出head和tail非法异常(非0且非字母)
    if(head == 0 && tail == 0){
        def::makeGraph(words,0);
        if(setjmp(def::buf) == 0)
            def::search();
        result = def::longestList;
    }
    else{
        if(head != 0 && tail == 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            if(setjmp(sHoT::buf) == 0)
                sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(words,true,true),head);
            sHoT::printSolution();
            result = sHoT::resultPath;
        }
        else if(head == 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            if(setjmp(sHoT::buf) == 0)
                sHoT::findPathWithSpecifiedTail(sHoT::buildGraph(words,true,false),tail);
            sHoT::printSolution();
            result = sHoT::resultPath;
        }
        else if(head != 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            if(setjmp(sHoT::buf) == 0)
                sHoT::findPathWithSpecifiedHeadAndTail(sHoT::buildGraph(words,true,true),head,tail);
            sHoT::printSolution();
            result = sHoT::resultPath;
        }
    }
    return result.size();
}

int CoreImplement::gen_chain_char(std::vector<std::string> &words, std::vector<std::string> &result, char head, char tail)
{   
    def::longestList.clear();
    sHoT::resultPath.clear();
    if (words.size()==0){
        expt::exception ex;
        ex.location="gen_chain_char";
        ex.message="No element in words.";
        throw ex;
    }
    // 抛出words为空异常
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::tolower);
        for (int j=0; j<words[i].length(); j++){
            if (words[i][j]<'a' || words[i][j]>'z'){
                expt::exception ex;
                ex.location="gen_chain_char";
                ex.message="At least one element of words is illegal.";
                throw ex;
            }
        }
    }
    // 抛出words非法异常(含有非字母字符)
    head=tolower(head);
    tail=tolower(tail);
    if (head!=0 && (head<'a' || head>'z')){
        expt::exception ex;
        ex.location="gen_chain_char";
        ex.message="Illegal head.";
        throw ex;
    }
    if (tail!=0 && (tail<'a' || tail>'z')){
        expt::exception ex;
        ex.location="gen_chain_char";
        ex.message="Illegal tail.";
        throw ex;
    }
    // 抛出head和tail非法异常(非0且非字母)

    if(head == 0 && tail ==0){
        def::makeGraph(words,1);
        if(setjmp(def::buf) == 0)
            def::search();

        result = def::longestList;
        
    }
    else{
        if(head != 0 && tail == 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            if(setjmp(sHoT::buf) == 0)
                sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(words,false,true),head);
            sHoT::printSolution();
            result = sHoT::resultPath;
        }
        else if(head == 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            if(setjmp(sHoT::buf) == 0)
                sHoT::findPathWithSpecifiedTail(sHoT::buildGraph(words,false,false),tail);
            sHoT::printSolution();
            result = sHoT::resultPath;
            
        }
        else if(head != 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            if(setjmp(sHoT::buf) == 0)
                sHoT::findPathWithSpecifiedHeadAndTail(sHoT::buildGraph(words,false,true),head,tail);
            sHoT::printSolution();
            result = sHoT::resultPath;
            
        }
        
    }
    return result.size();
}

int CoreImplement::all_chain_word(std::vector<std::string> &words, std::set<std::vector<std::string>> &result, int n, char head, char tail){
    if (words.size()==0){
        expt::exception ex;
        ex.location="all_chain_word";
        ex.message="No element in words.";
        throw ex;
    }
    // 抛出words为空异常
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::tolower);
        for (int j=0; j<words[i].length(); j++){
            if (words[i][j]<'a' || words[i][j]>'z'){
                expt::exception ex;
                ex.location="all_chain_word";
                ex.message="At least one element of words is illegal.";
                throw ex;
            }
        }
    }
    // 抛出words非法异常(含有非字母字符)
    head=std::tolower(head);
    tail=std::tolower(tail);
    if (head!=0 && (head<'a' || head>'z')){
        expt::exception ex;
        ex.location="all_chain_word";
        ex.message="Illegal head.";
        throw ex;
    }
    if (tail!=0 && (tail<'a' || tail>'z')){
        expt::exception ex;
        ex.location="all_chain_word";
        ex.message="Illegal tail.";
        throw ex;
    }
    // 抛出head和tail非法异常(非0且非字母)
    if(n<2){
        expt::exception ex;
        ex.location="all_chain_word";
        ex.message="As defined, word list must have a length at least 2.";
        throw ex;
    }
    // 抛出n小于2的异常
    if(head && tail) sWN::request4(words, n, head,tail);
    else if(head) sWN::request4(words, n,head,0);
    else if(tail) sWN::request4(words, n,0,tail);
    else sWN::request4(words, n);
    result = sWN::result;
    return result.size();
}

std::vector<std::string> CoreImplement::text_preprocess(std::string inputFile) {
    std::ifstream inFile(inputFile);
    if(!inFile){
        expt::exception ex;
        ex.message="Can not open data file.";
        ex.location="text_preprocess";
        throw ex;
    }
    // 抛出文件无法打开异常
    std::string crudeString;    //从输入文件读取的原始内容
    std::string tempString;
    while(!inFile.eof()){
        inFile>>tempString;
        crudeString.append(tempString);
        crudeString.append(" ");
    }
    //通过数据预处理得到的字符串向量，作为各功能部件的数据接口输入
    return sHoT::preprocessingData(crudeString);
}

std::vector<std::string> CoreImplement::preprocessingData(std::string crudeData){
    return sHoT::preprocessingData(crudeData);
}
/**
_declspec(dllexport)bool GetCore(void** _RtObject)
{
    Core* core = NULL;
    core = new CoreImplement();
    *_RtObject = (void*)core;
    return true;
}
**/