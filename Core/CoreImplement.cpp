#include "CoreImplement.h"
#include "specifiedHeadOrTail.h"
#include "specifiedWordNumbers.h"
#include "defaultCase.h"
#include <algorithm>
// g++ -fno=rtti test.cpp ../CoreImplement.cpp 
int CoreImplement::gen_chain_word(std::vector<std::string> &words, std::vector<std::string> &result, char head, char tail)
{   
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::tolower);
    }

    if(head == 0 && tail ==0){
        def::makeGraph(words,0);
        def::search();

        result = def::longestList;
        return result.size();
    }
    else{
        if(head != 0 && tail == 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(words,true,true),head);

            result = sHoT::resultPath;
            return result.size();
        }
        if(head == 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedTail(sHoT::buildGraph(words,true,false),tail);

            result = sHoT::resultPath;
            return result.size();
        }
        if(head != 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedHeadAndTail(sHoT::buildGraph(words,true,true),head,tail);

            result = sHoT::resultPath;
            return result.size();
        }
        return 0;
    }
}

int CoreImplement::gen_chain_char(std::vector<std::string> &words, std::vector<std::string> &result, char head, char tail)
{   
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::toupper);
    }

    if(head == 0 && tail ==0){
        def::makeGraph(words,1);
        def::search();

        result = def::longestList;
        return result.size();
    }
    else{
        if(head != 0 && tail == 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(words,false,true),head);

            result = sHoT::resultPath;
            return result.size();
        }
        if(head == 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedTail(sHoT::buildGraph(words,false,false),tail);

            result = sHoT::resultPath;
            return result.size();
        }
        if(head != 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedHeadAndTail(sHoT::buildGraph(words,false,true),head,tail);

            result = sHoT::resultPath;
            return result.size();
        }
        return 0;
    }
}

int CoreImplement::all_chain_word(std::vector<std::string> &words, std::set<std::vector<std::string>> &result, int n, char head, char tail){
    for(int i = 0;i < words.size();i++){
        transform(words[i].begin(),words[i].end(),words[i].begin(),::toupper);
    }

    if(head && tail) sWN::request4(words, n, head,tail);
    else if(head) sWN::request4(words, n,head,0);
    else if(tail) sWN::request4(words, n,0,tail);
    else sWN::request4(words, n);

    result = sWN::result;
    return result.size();
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