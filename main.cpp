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

    ifstream inFile(argv[argc - 1]);
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
    // for(int i = 0;i < crudeData.size();i++)
    //     std::cout<<crudeData[i]<<std::endl;
    if(strcmp(argv[1],"-h") == 0 && strlen(argv[2]) == 1 && argv[2][0] <= 'z' && argv[2][0] >= 'a'){
        sHoT::findPathWithSpecifiedHead(sHoT::buildGraph(crudeData),argv[2][0]);
        sHoT::printSolution();
    }
}