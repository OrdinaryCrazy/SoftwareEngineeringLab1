// This is a Software Engineering Group Project
// Contributor: DaiLu, WangHaoyu, ZhangJingtun
// Last modified: 20190311 17:01
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
    std::string usage="Usage: Wordlist [arguments] <filename>\r\n\
Mandatory arguments:\r\n\
    -c: Output one word list with the most characters. \r\n\
    -w: Output one word list with the most words.\r\n\r\n\
Optional arguments:\r\n\
    -h <char>: Determine the head character of the word list.\r\n\
    -t <char>: Determine the tail character of the word list.\r\n\
    (Note: -h and -t can be used at the same time)\r\n\
    -n <num>: Output all word lists containing <num> words.\r\n\
    (Note: -n must be used with -w)";
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
//    bool getInputFile = false;
    int wordNum;
    std::string inputFile;
    char head,tail;
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
                        if (i+1<argc-1) throw 0;
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
    /*
    if(getInputFile == false){
        std::cout<<"Please give input file name."<<std::endl;
        usage();
        exit(0);
    }
    */
    if (mostChar==mostWord || (fixedWordNum && (fixedTail || fixedHead || mostChar)) ){
        std::cout<< "Wrong argument usage." <<std::endl;
        usage();
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
        if (mostChar)   def::makeGraph(crudeData,1);
        else    def::makeGraph(crudeData,0);
        def::search();
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