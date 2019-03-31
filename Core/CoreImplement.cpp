#include "CoreImplement.h"
#include "specifiedHeadOrTail.h"
#include "specifiedWordNumbers.h"
#include "defaultCase.h"
#include <algorithm>
#include <setjmp.h>
// g++ -fno-rtti test.cpp ../CoreImplement.cpp 

int CoreImplement::gen_chain_word(std::vector<std::string> &words, std::vector<std::string> &result, char head, char tail)
{   
    def::longestList.clear();
    sHoT::resultPath.clear();
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::tolower);
    }

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
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::tolower);
    }

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

int CoreImplement::all_chain_word(std::vector<std::string> &words, std::set<std::vector<std::string>> &result, int n, int& error_flag, char head, char tail){
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::tolower);
    }

    if(head && tail) sWN::request4(words, n, head,tail);
    else if(head) sWN::request4(words, n,head,0);
    else if(tail) sWN::request4(words, n,0,tail);
    else sWN::request4(words, n);

    result = sWN::result;
    error_flag = sWN::error_flag;
    return result.size();
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