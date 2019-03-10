#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
namespace sHoT{
    // graph datastructure
    struct edge{
        std::string* data;
        int weight;
        char destChar;
        char originChar;
        bool used;
        struct edge* next;
    };
    typedef struct edge edge;
    struct node{
        char ch;
        edge* adjEdges;
    };
    typedef struct node node;
    // global variable
    std::vector<std::string> searchingPath;
    int searchingWeight;
    std::vector<std::string> resultPath;
    int resultWeight;
    //
    // build graph from crude string data
    node* buildGraph(std::vector<std::string> crudeData,bool mostWord = true,bool headOrder = true){
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
            inputEdge->originChar = crudeData[i][0];
            if(mostWord){
                inputEdge->weight = 1;
            }
            else{
                inputEdge->weight = crudeData[i].length();
            }
            int insertNode;
            if(headOrder){
                insertNode = crudeData[i][0] - 97;
            }
            else{
                insertNode = crudeData[i][crudeData[i].length() - 1] - 97;
            }
            inputEdge->next = graph[insertNode].adjEdges;
            graph[insertNode].adjEdges = inputEdge;
        }
        searchingWeight = resultWeight = 0;
        // std::cout<< "Graph building finished." <<std::endl;
        return graph;
    }
    
    void findPathWithSpecifiedHead(node* graph,char head){
        edge* fromEdge = graph[head - 'a'].adjEdges;
        while(fromEdge != NULL){
            if(fromEdge->used == false){

                fromEdge->used = true;
                searchingPath.push_back(*(fromEdge->data));
                searchingWeight += fromEdge->weight;

                findPathWithSpecifiedHead(graph,fromEdge->destChar);
                
                searchingWeight -= fromEdge->weight;
                fromEdge->used = false;
                searchingPath.pop_back();
            }
            fromEdge = fromEdge->next;
        }
        if(searchingWeight > resultWeight){
            resultWeight = searchingWeight;
            resultPath.assign(searchingPath.begin(),searchingPath.end());
            resultPath.reserve(resultPath.size());
        }
    }

    void findPathWithSpecifiedTail(node* graph,char tail){
        edge* fromEdge = graph[tail - 'a'].adjEdges;
        while(fromEdge != NULL){
            if(fromEdge->used == false){

                fromEdge->used = true;
                searchingPath.push_back(*(fromEdge->data));
                searchingWeight += fromEdge->weight;

                findPathWithSpecifiedTail(graph,fromEdge->originChar);
                
                searchingWeight -= fromEdge->weight;
                fromEdge->used = false;
                searchingPath.pop_back();
            }
            fromEdge = fromEdge->next;
        }
        if(searchingWeight > resultWeight){
            resultWeight = searchingWeight;
            resultPath.assign(searchingPath.begin(),searchingPath.end());
            reverse(resultPath.begin(),resultPath.end());
        }
    }
    void findPathWithSpecifiedHeadAndTail(node* graph,char head,char tail){
        if(head == tail && searchingWeight > resultWeight){
            resultWeight = searchingWeight;
            resultPath.assign(searchingPath.begin(),searchingPath.end());
        }
        edge* fromEdge = graph[head - 'a'].adjEdges;
        while(fromEdge != NULL){
            if(fromEdge->used == false){

                fromEdge->used = true;
                searchingPath.push_back(*(fromEdge->data));
                searchingWeight += fromEdge->weight;

                findPathWithSpecifiedHeadAndTail(graph,fromEdge->destChar,tail);
                
                searchingWeight -= fromEdge->weight;
                fromEdge->used = false;
                searchingPath.pop_back();
            }
            fromEdge = fromEdge->next;
        }
    }
    void printSolution(){
        std::ofstream solutionOut("./solution.txt");
        for(int i = 0;i < resultPath.size();i++){
            solutionOut<<resultPath[i]<<std::endl;
        }
    }
    std::vector<std::string> preprocessingData(std::string crudeData){
        // std::cout<<crudeData<<std::endl;
        std::vector<std::string> wordList = std::vector<std::string>();
        char* charData = const_cast<char*>(crudeData.c_str());
        std::string stringData;
        int len = strlen(charData);
        for(int i = 0;i < len;i++){
            if(charData[i] <= 'z' && charData[i] >= 'a'){
                stringData.append(1,charData[i]);
            }
            else if(charData[i] <= 'Z' && charData[i] >= 'A'){
                stringData.append(1,(char)(charData[i] + 32));
            }
            else{
                stringData.append(1,' ');
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