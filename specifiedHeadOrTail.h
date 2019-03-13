#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
namespace sHoT{
    // graph datastructure
    struct edge{
        std::string* data;  //边对应的单词
        int weight;         //边的权重，根据模式的不同分别设置为1或单词的长度
        char destChar;      //有向边的目的节点
        char originChar;    //有向边的源节点
        bool used;          //使用标志位，避免重复搜索
        struct edge* next;
    };
    typedef struct edge edge;
    struct node{
        char ch;            //节点对应的字母
        edge* adjEdges;     //邻接链表
    };
    typedef struct node node;

    // global variable
    std::vector<std::string> searchingPath; //当前搜索路径（单词链）
    int searchingWeight;                    //当前搜索路径的权重（长度）
    std::vector<std::string> resultPath;    //当前搜索过的最长路径（单词链）
    int resultWeight;                       //当前搜索过的最长路径的权重（长度）

    // build graph from crude string data
    node* buildGraph(std::vector<std::string> crudeData,bool mostWord = true,bool headOrder = true){
        /*  参数说明：
                1、std::vector<std::string> crudeData 输入字符向量
                2、mostWord 是否开启最多单词模式（默认为最多单词模式）
                3、headOrder 是否以首字母为源节点（固定开头字母时使用，默认固定开头字母模式）
            输出：
                以26个英文字母对应的节点数组表示的图
        */
        //节点数组
        node* graph = new node[26];
        for(int i = 0;i < 26;i++){
            graph[i].ch = 97 + i;
            graph[i].adjEdges = NULL;
        }
        //读取数据连接对应的边
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

        return graph;
    }
    // 固定开头字母模式
    void findPathWithSpecifiedHead(node* graph,char head){
        /*  参数说明：
                1、node* graph 要搜索的图
                2、char head 当前搜索节点
            输出：无输出，将最长路径保存在 resultPath 中
        */
        edge* fromEdge = graph[head - 'a'].adjEdges;
        while(fromEdge != NULL){
            if(fromEdge->used == false){

                fromEdge->used = true;
                searchingPath.push_back(*(fromEdge->data));
                searchingWeight += fromEdge->weight;
                //DFS递归搜索
                findPathWithSpecifiedHead(graph,fromEdge->destChar);
                
                searchingWeight -= fromEdge->weight;
                fromEdge->used = false;
                searchingPath.pop_back();
            }
            fromEdge = fromEdge->next;
        }
        //每条路径搜索结束后与当前搜索到的最长路径比较，如果更长则更新最长路径及最长路径权重
        if(searchingWeight > resultWeight){
            resultWeight = searchingWeight;
            resultPath.assign(searchingPath.begin(),searchingPath.end());
            //resultPath.reserve(resultPath.size());
        }
    }
    // 固定结尾字母模式
    void findPathWithSpecifiedTail(node* graph,char tail){
        /*  参数说明：
                1、node* graph 要搜索的图
                2、char tail 当前搜索节点
            输出：无输出，将最长路径保存在 resultPath 中
        */
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
    //固定开头字母和结尾字母模式
    void findPathWithSpecifiedHeadAndTail(node* graph,char head,char tail){
        /*  参数说明：
                1、node* graph 要搜索的图
                2、char tail 最终目标结尾节点
                3、char head 当前搜索节点
            输出：无输出，将最长路径保存在 resultPath 中
        */
        //并不是在每条路径末尾与最长路径比较，而是当发现到达目标节点时更新最长路径
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
        sort(wordList.begin(),wordList.end());
        /*
        for(int i = 0;i < wordList.size();i++)
            std::cout<<wordList[i]<<std::endl;
        std::cout<<std::endl;
        */
        std::vector<std::string>::iterator iter = unique(wordList.begin(),wordList.end());
        wordList.erase(iter,wordList.end());
        /*
        for(int i = 0;i < wordList.size();i++)
            std::cout<<wordList[i]<<std::endl;
        */
        return wordList;
    }
}