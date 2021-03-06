#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <signal.h>
#include <setjmp.h>
#include "exception.h"
namespace def{
struct node{
    int weight;
    bool used;
    std::string *data;
    struct node *next;
    char lastChar;
};
// 有向图的节点定义
node *graph[26];
// 有向图的邻接链表表示
std::vector<std::string> currentList;
// 存储当前的单词链
std::vector<std::string> longestList;
// 存储至今最长的单词链
int currentWeight,longestWeight;
// 存储当前单词链和最长单词链的总权重

jmp_buf buf;

void makeGraph(std::vector<std::string> s,int type){
    // s是字符串向量，保存所有的单词；type是类型，0表示按单词数目，1表示按照字母数目
    for (int i=0;i<26;i++){
        graph[i]=(node *) malloc(sizeof(node));
        graph[i]->next=NULL;
    }// 生成头节点
    for (int i=0;i<s.size();i++){
        node* temp=(node *) malloc(sizeof(node));
        //temp->next=NULL;
        temp->data=new std::string(s[i]);
        temp->used=false;
        temp->lastChar=s[i][s[i].length()-1];
        if (type==0){
            temp->weight=1;
        }
        else{
            temp->weight=s[i].length();
        }
        // 根据不同的类型决定边的权重
        int t=s[i][0]-'a';
        //printf("%d",t);
        temp->next=graph[t]->next;
        graph[t]->next=temp;
        // 使用头插法将节点插入链表
    }// 生成所有的边
} 

void DFS(node *curr){
    // 深度优先搜索，curr是一个节点的指针
    node *temp=curr->next;
    //std::cout<<*(temp->data)<<curr->lastChar;
    while(temp!=NULL){
        if (!temp->used){
            temp->used=true;
            currentList.push_back(*(temp->data));
            currentWeight+=temp->weight;
            // 标记使用的边，并在当前单词链中追加单词并增加总权重
            DFS(graph[temp->lastChar-'a']);
            // 搜索当前边指向的节点
            temp->used=false;
            currentList.pop_back();
            currentWeight-=temp->weight;
            // 回溯，去除标记并在当前单词链中删除单词并减少总权重
        }
        temp=temp->next;
    }
    if (currentWeight>longestWeight){
        //printf("\r\nbegin copy");
        longestList.assign(currentList.begin(),currentList.end());
        longestWeight=currentWeight;
        //printf("\r\nend");
    }
    // 如果当前单词链长于最长的单词链，就进行把当前单词链作为最长单词链
}

void signalHandler(int m){
    //超时处理函数：输出DFS当前查找到的最长单词链
    std::cout<<"Time limits. The word list output may not be the longest one."<<std::endl;
    std::ofstream mycout("solution.txt");
    for (int i=0;i<longestList.size();i++){
        mycout<<longestList[i]<<std::endl;
    }
    //exit(0);
    //return;
    longjmp(buf,1);
}

void initTimer(int sec){
    //设置定时器，搜索sec秒后停止搜索
    struct itimerval value;
    value.it_value.tv_sec=sec;
    value.it_value.tv_usec=0;
    value.it_interval=value.it_value;
    setitimer(ITIMER_REAL,&value,NULL);
}
void search(){  
    signal(SIGALRM, signalHandler);
    initTimer(15);
    for (int i=0;i<26;i++){
        if (graph[i]->next!=NULL){
            //printf("%c",i+'a');
            DFS(graph[i]);
        }
    }
    // 对所有的节点进行深度优先搜索
    if (longestList.size()<2){
        expt::exception ex;
        ex.location="search";
        ex.message="Sorry for no finding of Wordlist.";
        throw ex;
    }
    else{
        std::ofstream mycout("solution.txt");
        for (int i=0;i<longestList.size();i++){
            mycout<<longestList[i]<<std::endl;
        }
    }   
    // 输出最长的单词链
}
}
