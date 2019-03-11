# SoftwareEngineeringLab1
This is a group project repository.

# 需要讨论确定的内容

* 总体思想：

#### 3月9日上午讨论确定：

1. 以字母为节点，单词为边
2. 边的数据结构中要有data，wordweight，lengthweight，used，next几个域

3月9日下午：

1. 函数直接传原始数据vector< string>，各自根据需要建立图数据结构，简化函数间的联系方便后面加功能（__string中的字母全部小写__）

* 变量命名规范：

> 驼峰命名（首字母小写），如：maxFinding()

* 图的数据结构：

* 主函数与功能函数接口：

# 具体实现细节

## 入口主函数

## 单词数量最多的单词链
构建有向图，以单词为边，以字母为节点，采用邻接链表形式存储。链表节点结构如下:
```C++
struct node{
    int weight;
    bool used;
    std::string *data;
    struct node *next;
    char lastChar;
};
```
一个链表节点代表一条边，或者是不代表边的头节点。  
对于边节点：weight恒为1；used标记边是否被使用（用于DFS防止重复搜索）；data指向一个字符串，存放该边对应的单词；next指向链表中的下一个节点或为NULL；lastChar是该单词的最后一个字母，用于指示该有向边指向的节点。  
对于头结点：next指向链表中的下一个节点或为NULL；其余字段无意义。  
全局变量如下：
```C++
node *graph[26];
// 有向图的邻接链表表示
std::vector<std::string> currentList;
// 存储当前的单词链
std::vector<std::string> longestList;
// 存储至今最长的单词链
int currentWeight,longestWeight;
// 存储当前单词链和最长单词链的总权重
```
DFS可以得到从一个图节点（字母）出发导出的所有单词链。由于没有指定开头的字母，应当对所有的节点进行深度优先搜索，输出最长的单词链。  
在具体使用中，可以使用如下的代码：
```C++
def::makeGraph(s,0);
def::search();
```
其中s是一个字符串向量std::vector < std::string >,而且每一个单词都应当全部由小写字母组成。最后的结果会输出到与可执行文件同目录的solution.txt文件中。

## 字母最多的单词链
在实现上与单词数量最多的单词链基本没有不同，只是把节点权重设置为单词长度而不是1。
在具体使用中，可以使用如下的代码：
```C++
def::makeGraph(s,1);
def::search();
```
输入输出要求同上。

## 指定开头或结尾的字母的单词链

## 指定单词链个数的单词链

## GUI

