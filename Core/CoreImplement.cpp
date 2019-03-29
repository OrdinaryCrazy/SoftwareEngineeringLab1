#include "CoreImplement.h"
#include "specifiedHeadOrTail.h"
#include "specifiedWordNumbers.h"
#include "defaultCase.h"
#include <algorithm>
#include <string>

int CoreImplement::gen_chain_word(char* words[], int len, char* result[], char head, char tail)
{
    std::vector<std::string> wordList = std::vector<std::string>();
    for(int i = 0;i < len;i++){
        std::string tmp = std::string(words[i]);
        transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
        wordList.push_back(tmp);
    }
    sort(wordList.begin(),wordList.end());
    std::vector<std::string>::iterator iter = unique(wordList.begin(),wordList.end());
    wordList.erase(iter,wordList.end());

    if(head == 0 && tail ==0){
        def::makeGraph(wordList,0);
        def::search();

        result = new char*[def::longestList.size()];
        for(int i = 0;i < def::longestList.size();i++){
            result[i] = def::longestList[i].toCharArray();
        }
        return def::longestList.size();
    }
    else{
        if(head != 0 && tail == 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(wordList,true,true),head);

            result = new char*[sHoT::resultPath.size()];
            for(int i = 0;i < sHoT::resultPath.size();i++){
                result[i] = sHoT::resultPath[i].toCharArray();
            }
            return sHoT::resultPath.size();
        }
        if(head == 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedTail(sHoT::buildGraph(wordList,true,false),tail);

            result = new char*[sHoT::resultPath.size()];
            for(int i = 0;i < sHoT::resultPath.size();i++){
                result[i] = sHoT::resultPath[i].toCharArray();
            }
            return sHoT::resultPath.size();
        }
        if(head != 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedHeadAndTail(sHoT::buildGraph(wordList,true,true),head,tail);

            result = new char*[sHoT::resultPath.size()];
            for(int i = 0;i < sHoT::resultPath.size();i++){
                result[i] = sHoT::resultPath[i].toCharArray();
            }
            return sHoT::resultPath.size();
        }
    }
}

int CoreImplement::gen_chain_char(char* words[], int len, char* result[], char head, char tail)
{
    std::vector<std::string> wordList = std::vector<std::string>();
    for(int i = 0;i < len;i++){
        std::string tmp = std::string(words[i]);
        transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
        wordList.push_back(tmp);
    }
    sort(wordList.begin(),wordList.end());
    std::vector<std::string>::iterator iter = unique(wordList.begin(),wordList.end());
    wordList.erase(iter,wordList.end());

    if(head == 0 && tail ==0){
        def::makeGraph(wordList,1);
        def::search();

        result = new char*[def::longestList.size()];
        for(int i = 0;i < def::longestList.size();i++){
            result[i] = def::longestList[i].toCharArray();
        }
        return def::longestList.size();
    }
    else{
        if(head != 0 && tail == 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(wordList,false,true),head);

            result = new char*[sHoT::resultPath.size()];
            for(int i = 0;i < sHoT::resultPath.size();i++){
                result[i] = sHoT::resultPath[i].toCharArray();
            }
            return sHoT::resultPath.size();
        }
        if(head == 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedTail(sHoT::buildGraph(wordList,false,false),tail);

            result = new char*[sHoT::resultPath.size()];
            for(int i = 0;i < sHoT::resultPath.size();i++){
                result[i] = sHoT::resultPath[i].toCharArray();
            }
            return sHoT::resultPath.size();
        }
        if(head != 0 && tail != 0){
            signal(SIGALRM, sHoT::signalHandler);
            sHoT::initTimer(15);
            sHoT::findPathWithSpecifiedHeadAndTail(sHoT::buildGraph(wordList,false,true),head,tail);

            result = new char*[sHoT::resultPath.size()];
            for(int i = 0;i < sHoT::resultPath.size();i++){
                result[i] = sHoT::resultPath[i].toCharArray();
            }
            return sHoT::resultPath.size();
        }
    }
}
_declspec(dllexport)bool GetCore(void** _RtObject)
{
    Core* core = NULL;
    core = new CoreImplement();
    *_RtObject = (void*)core;
    return true;
}