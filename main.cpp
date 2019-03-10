// This is a Software Engineering Group Project
// Contributor: DaiLu, WangHaoyu, ZhangJingtun
// Last modified: 20190310 10:22
#include "specifiedHeadOrTail.h"
#include "wang.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>

int main (int argc, char*argv[]){
    using namespace sHoT;
    using namespace wang;
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
                        inputFile = std::string(argv[i + 1]);
                        break;
                    case 'c':
                        mostChar = true;
                        getInputFile = true;
                        inputFile = std::string(argv[i + 1]);
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
                        wordNum = stoi(std::string(argv[i + 1]));
                        break;
                    default:
                        std::cout<< "invalid option." <<std::endl;
                        break;
                }
                break;
        
            default:
                break;
        }
    }
    if(getInputFile == false){
        std::cout<<"Please give input file name."<<std::endl;
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

    if(fixedHead && head <= 'z' && head >= 'a'){
        sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(crudeData),argv[2][0]);
        sHoT::printSolution();
    }

}