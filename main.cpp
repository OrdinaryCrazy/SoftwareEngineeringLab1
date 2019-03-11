// This is a Software Engineering Group Project
// Contributor: DaiLu, WangHaoyu, ZhangJingtun
// Last modified: 20190310 10:22
#include "specifiedHeadOrTail.h"
#include "specifiedWordNumbers.h"
#include "defaultCase.h"
#include <iostream>
#include <algorithm>
#include <vector> 
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>
void usage(){
    std::string usage="Usage: Wordlist [options] <filename>\r\nOptions:\r\n\
    -c: Output one word list with the most characters. \r\n\
    -w: Output one word list with the most words.\r\n\
    (Note: -c or -w must be used as the last option argument)\r\n\r\n\
    -h <char>: Determine the head character of the word list.\r\n\
    -t <char>: Determine the tail character of the word list.\r\n\
    (Note: -h and -t can be used at the same time)\r\n\
    -n <num>: Output all word lists containing <num> words.\r\n";
    cout<<usage;
    exit(1);
}
int main (int argc, char*argv[]){
    using namespace sHoT;
    using namespace def;
    using namespace std;

    bool mostChar = false;
    bool mostWord = false;
    bool fixedWordNum = false;
    bool fixedHead = false;
    bool fixedTail = false;
    bool getInputFile = false;
    int wordNum;
    std::string inputFile;
    char head,tail;

    for(int i = 0;i < argc;i++){
        switch (argv[i][0]){
            case '-':
                switch (argv[i][1]){
                    case 'w':
                        mostWord = true;
                        getInputFile = true;
                        if (i+1<argc){
                            inputFile = std::string(argv[i + 1]);
                        }   
                        else {
                            std::cout<<"Please give input file name."<<std::endl;
                            usage();
                        }
                        break;
                    case 'c':
                        mostChar = true;
                        getInputFile = true;
                        if (i+1<argc){
                            inputFile = std::string(argv[i + 1]);
                        }
                        else{
                            std::cout<<"Please give input file name."<<std::endl;
                            usage();
                        }                        
                        break;
                    case 'h':
                        fixedHead = true;
                        head = argv[i + 1][0];
                        break;
                    case 't':
                        fixedTail = true;
                        tail = argv[i + 1][0];
                        break;
                    case 'n':
                        fixedWordNum = true;
                        if (i+1<argc){
                            wordNum = stoi(std::string(argv[i + 1]));
                        }
                        else{
                            std::cout<<"Please give the number of words."<<std::endl;
                            usage();
                        }                              
                        break;
                    default:
                        std::cout<< "invalid option." <<std::endl;
                        usage();
                        break;
                }
                break;
        
            default:
                break;
        }
    }
    if(getInputFile == false){
        std::cout<<"Please give input file name."<<std::endl;
        usage();
        exit(0);
    }
    ifstream inFile(inputFile);
    if(!inFile){
        std::cout<<"Can not open data file."<<std::endl;
        exit(0);
    }
    std::string crudeString;
    std::string tempString;
    while(!inFile.eof()){
        inFile>>tempString;
        crudeString.append(tempString);
        crudeString.append(" ");
    }
    std::vector<std::string> crudeData = sHoT::preprocessingData(crudeString);
    if (!fixedHead && !fixedTail && !fixedWordNum){
        if (mostChar){
            def::makeGraph(crudeData,1);
            def::search();
        }
        else if (mostWord){
            def::makeGraph(crudeData,0);
            def::search();
        }
        else {
            usage();
        }
    }
    if(fixedHead && !fixedTail && head <= 'z' && head >= 'a'){
        if(mostWord || (mostChar == false && mostWord == false)){
            sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(crudeData,true,true),head);
        }
        if(mostChar){
            sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(crudeData,false,true),head);
        }
        sHoT::printSolution();
    }
    if(!fixedHead && fixedTail && tail <= 'z' && tail >= 'a'){
        if(mostWord || (mostChar == false && mostWord == false)){
            sHoT::findPathWithSpecifiedTail(sHoT::buildGraph(crudeData,true,false),tail);
        }
        if(mostChar){
            sHoT::findPathWithSpecifiedTail(sHoT::buildGraph(crudeData,false,false),tail);
        }
        sHoT::printSolution();
    }
    if(fixedHead && fixedTail && head <= 'z' && head >= 'a' && tail <= 'z' && tail >= 'a'){
        if(mostWord || (mostChar == false && mostWord == false)){
            sHoT::findPathWithSpecifiedHeadAndTail(sHoT::buildGraph(crudeData,true,true),head,tail);
        }
        if(mostChar){
            sHoT::findPathWithSpecifiedHeadAndTail(sHoT::buildGraph(crudeData,false,true),head,tail);
        }
        sHoT::printSolution();
    }
    if(fixedWordNum){
        sWN::request4(crudeData, wordNum);
    }
}