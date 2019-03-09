# SoftwareEngineeringLab1
This is a group project repository.

# 需要讨论确定的内容

* 总体思想：

#### 3月9日讨论确定：

1. 以字母为节点，单词为边
2. 边的数据结构中要有data，wordweight，lengthweight，used，next几个域

* 变量命名规范：

> 驼峰命名（首字母小写），如：maxFinding()

* 图的数据结构：

```c++
struct edge{
    string data;
    int wordweight;
	int lengthweight;
    bool used;
    char last;
    struct edge * next;
}
typedef struct edge edge;
struct node{
    char ch;
    edge* startEdges;
}
typedef struct node node;
```



* 主函数与功能函数接口：

# 具体实现细节

## 入口主函数

## 单词数量最多的单词链

## 字母最多的单词链

## 指定开头或结尾的字母的单词链

## 指定单词链个数的单词链

## GUI

