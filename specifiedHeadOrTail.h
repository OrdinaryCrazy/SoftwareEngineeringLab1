#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
namespace sHoT{
    // graph datastructure
    struct edge{
        std::string* data;
        char destChar;
        bool used;
        struct edge* next;
    };
    typedef struct edge edge;
    struct node{
        char ch;
        edge* adjEdges;
    };
    typedef struct node node;
    // build graph from crude string data
    node* buildGraph(std::vector<std::string> crudeData){
        node* graph = new node[26];
        for(int i = 0;i < 26;i++){
            graph[i].ch = 97 + i;
            graph[i].adjEdges = NULL;
        }
        for(int i = 0;i < crudeData.size();i++){
            edge* inputEdge = new edge;
            inputEdge->data = new std::string(crudeData[i]);
            inputEdge->next = NULL;
            inputEdge->used = false;
            inputEdge->destChar = crudeData[i][crudeData[i].length() - 1];
            int insertNode = crudeData[i][0] - 97;
            inputEdge->next = graph[insertNode].adjEdges;
            graph[insertNode].adjEdges = inputEdge;
        }
        // std::cout<< "Graph building finished." <<std::endl;
        return graph;
    }
    // global variable
    std::vector<std::string> searchingPath;
    std::vector<std::string> resultPath;
    //
    void findPathWithSpecifiedHead(node* graph,char head){
        if(searchingPath.size() > 1){
            if(searchingPath.size() != resultPath.size()){
                resultPath.assign(searchingPath.begin(),searchingPath.end());
            }
            return;
        }
        if(graph[head - 'a'].adjEdges != NULL){
            edge* fromEdge = graph[head - 'a'].adjEdges;
            while(fromEdge != NULL){
                if(fromEdge->used == false){
                    fromEdge->used == true;
                    searchingPath.push_back(*(fromEdge->data));
                    findPathWithSpecifiedHead(graph,fromEdge->destChar);
                    fromEdge->used = false;
                    searchingPath.pop_back();
                }
                fromEdge = fromEdge->next;
            }
        }
    }

    void findPathWithSpecifiedTail(node* graph,char tail){

    }
    void findPathWithSpecifiedHeadAndTail(node* graph,char head,char tail){

    }
    void printSolution(){
        std::ofstream solutionOut("./solution.txt");
        for(int i = 0;i < resultPath.size();i++){
            solutionOut<<resultPath[i]<<std::endl;
        }
    }
    std::vector<std::string> preprocessingData(std::string crudeData){
        std::cout<<crudeData<<std::endl;
        std::vector<std::string> wordList = std::vector<std::string>();
        char* charData = const_cast<char*>(crudeData.c_str());
        std::string stringData;
        int len = strlen(charData);
        for(int i = 0;i < len;i++){
            if(charData[i] == ' '){
                stringData.append(1,charData[i]);
            }
            if(charData[i] <= 'z' && charData[i] >= 'a'){
                stringData.append(1,charData[i]);
            }
            if(charData[i] <= 'Z' && charData[i] >= 'A'){
                stringData.append(1,(char)(charData[i] + 32));
            }
        }
        charData = const_cast<char*>(stringData.c_str());
        char* tokenPtr = strtok(charData," ");
        while(tokenPtr != NULL){
            wordList.push_back(std::string(tokenPtr));
            tokenPtr = strtok(NULL," ");
        }
        return wordList;
    }
}