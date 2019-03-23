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

* 功能控制开关说明：

```C++
bool mostChar = false; 				//最多字母模式开关
bool mostWord = false;				//最多单词模式开关
bool fixedWordNum = false;		//确定单词数量模式开关
bool fixedHead = false;					//确定开头字母模式开关
bool fixedTail = false;						//确定结尾字母模式开关
```

* 主要变量说明：

```c++
int wordNum;					//确定单词数量模式对应的单词数量
std::string inputFile;		//数据文件名
char head,tail;					//确定的开头字母和结尾字母
std::string crudeString;	//从输入文件读取的原始内容
std::vector<std::string> crudeData = sHoT::preprocessingData(crudeString);
//通过数据预处理得到的字符串向量，作为各功能部件的数据接口输入
```

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

## 指定开头或结尾的字母的单词链（`specifiedHeadOrTail.h`）

* 图数据结构及`sHoT`命名空间全局变量含义说明

```c++
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
    int resultWeight;                       //当前搜索过的最长路径的权重（长
```

* 建图函数说明

  ```c++
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
  ```

  

* 固定开头字母搜索

```c++
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
```



* 固定结尾字母搜索（与固定开头字母搜索没有太大区别，因为对应图结构已按照要求调整，只需要将最后结果反转即可）
```c++
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
```

* 同时固定开头和结尾字母搜索

```c++
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
```
## 指定单词链个数的单词链


## GUI

###  开发环境：

  > 操作系统：Ubuntu 18.10
  >
  > 编译环境：g++ (Ubuntu 8.2.0-7ubuntu1) 8.2.0
  >
  > 图形库：Qt 5.12.0 GCC64bit
  >
  > 设计工具：Qt Creator 4.8.0
  >
  > 依赖库说明：将上述命令行程序作为依赖库添加在图形化程序目录下，重命名为`WordlistCUI`

### 界面说明及控件对应关系：

![](./GUI.png)

* 输入区：`QPlainTextEdit InputText`
* 输出区：`QTextBrowser outputText`
* 最多单词数量：`QRadioButton mostWordCheck`
* 最多字母数量：`QRadioButton mostCharCheck`
* 固定开头：`QCheckBox fixHeadCheck`
* 固定开头输入：`QLineEdit fixHead`
* 固定结尾：`QCheckBox fixTailCheck`
* 固定结尾输入：`QLineEdit fixTail`
* 固定单词数量：`QCheckBox fixNumCheck`
* 固定单词数量选择：`QSpinBox fixNumber`
* 搜索单词链：`QPushButton convertButton `
* 从文件加载输入：`QPushButton loadFromFile `
* 将结果导出到文件：`QPushButton saveOutputFile `

### 槽函数处理：

<h4><font color=red><B>注 ：（这里使用了Qt自动关联，on_xxx_clicked() 槽函数自动关联到xxx部件信号）</B></font></h4>

* 处理搜索命令信号：`void MainWindow::on_convertButton_clicked()`

> 创建`QProcess`实例准备调用命令行程序 ---> 
>
> 将输入区文本保存为临时文件`tempInputFile.txt` --->
>
> 检查各参数对应的部件信号，处理不合法信号组合并给出提示，根据相应的信号设置命令行参数--->
>
> 调用命令行程序--->
>
> 将结果从文件读出并打印在输出文本区-->
>
> 清理临时文件

* 处理从文件加载输入信号：`void MainWindow::on_loadFromFile_clicked()`

> `QFileDialog::getOpenFileName()`函数获取选择的文件名---> 
>
> 读取相应的文件并将内容打印在输入区

* 处理将结果输出到文件信号：`void MainWindow::on_saveOutputFile_clicked()`

> `QFileDialog::getSaveFileName`函数获取选择的文件名---> 
>
> 新建输出文件将输出区文本写到输出文件

* 处理命令行返回的找不到单词链的信息：`oid MainWindow::Result(int a)`

> 将信号连接到标准输出-->
>
> CUI退出值为1时提供提示信息

## 测试样例说明
+ test1.txt是题目中给出的测试样例
+ test2.txt主要测试预处理能力，是否可以正确地分割输入字符得到单词，以及对于字母大小写的处理是否正确
+ test3.txt测试程序是否处理了不同搜索起点的情况，该样例从不同的起点开始得到的搜索结果长度不同
+ test4.txt提供了一幅4个顶点的有向完全图，可以测试程序的搜索性能
+ test5.txt，提供了一幅只有两个节点的图，可以测试程序的搜索是否完全，-n参数输出的路径条数是否正确

## 超时处理
由于算法的时间复杂度是指数级的，因此在对于复杂问题进行处理时可能会花费过长时间，因此我们设置了超时机制，如果搜索时间超过15秒，就停止搜索，输出当前得到的最长的单词链。
```C
void signalHandler(int m){
    //超时处理函数：输出DFS当前查找到的最长单词链
    std::cout<<"Time limits. The word list output may not be the longest one."<<std::endl;
    std::ofstream mycout("solution.txt");
    for (int i=0;i<longestList.size();i++){
        mycout<<longestList[i]<<std::endl;
    }
    exit(0);
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
    ...
}
```