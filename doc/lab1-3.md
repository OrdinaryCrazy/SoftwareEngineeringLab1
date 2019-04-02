# Lab1-c实验文档
> 小组成员
>
> PB16111485 张劲暾&emsp;&emsp;PB16080210 戴路&emsp;&emsp; PB16110428 王浩宇
## 实验需求
+ 将输入的处理封装为一个API，参数是输入文件名，返回处理后的不含重复单词的词语。
+ 使用异常进行错误处理，使得程序更加健壮。修改后的Core模块在遇到错误时会抛出异常。对于每一种异常都需要增加单元测试。
+ 回归测试所有以前的功能,保证以前的功能还能继续工作。
+ 使用封装好的API重构第一次提交的工程。

## 使用说明
### 单元测试
测试环境：Ubuntu 16.04  
库依赖：gcov, lcov, firefox浏览器  
1. 进入文件夹  
    假设当前位于本仓库中
    ```bash
    cd ./Core/unit_test
    ```
2. 编译
    ```bash
    make
    ```
    一键编译后，在命令行会输出测试是否通过的结果，firefox浏览器中会输出单元测试覆盖率情况
3. 清理
    ```bash
    make clean
    ```
    自动删除编译过程产生的所有文件
### 工程编译
测试环境：Ubuntu 16.04  
使用如下的命令编译整个工程：
```bash
make
```
## 文本处理
### 函数功能
+ 参数：文件名
+ 返回：处理好的字符串向量，存放所有的单词  
+ 功能：根据文件名读取输入文件，将非英文字母作为分隔符，从输入中获取单词，去除重复单词并按字典序排序
+ 异常：当输入文件不存在时将抛出异常
### 函数接口
Core模块中该功能的API为：
```C++
std::vector<std::string> text_preprocess(std::string inputFile) 
```
### 具体实现
将从输入文件中读取的原始内容作为一个字符串，遍历，进行如下处理：
+ 对于所有大写字母，转化为小写字母
+ 对于所有小写字母，不进行变动
+ 对于非英文字母，转化为空格  

对处理后的字符串，使用strtok()函数，以空格为分隔符，分割得到所有的单词。之后，使用sort()函数排序并使用unique()去重。
```C++
std::vector<std::string> CoreImplement::text_preprocess(std::string inputFile) {
    std::ifstream inFile(inputFile);
    if(!inFile){
        expt::exception ex;
        ex.message="Can not open data file.";
        ex.location="text_preprocess";
        throw ex;
    }
    // 抛出文件无法打开异常
    std::string crudeString;    //从输入文件读取的原始内容
    std::string tempString;
    while(!inFile.eof()){
        inFile>>tempString;
        crudeString.append(tempString);
        crudeString.append(" ");
    }
    //通过数据预处理得到的字符串向量，作为各功能部件的数据接口输入
    return sHoT::preprocessingData(crudeString);
}

std::vector<std::string> preprocessingData(std::string crudeData){
    std::vector<std::string> wordList = std::vector<std::string>();
    char* charData = const_cast<char*>(crudeData.c_str());
    std::chuling stringData;
    int lchuli strlen(charData);
    for(ichuli = 0;i < len;i++){
        ichuliarData[i] <= 'z' && charData[i] >= 'a'){
         chulitringData.append(1,charData[i]);
        }chuli
        echuliif(charData[i] <= 'Z' && charData[i] >= 'A'){chuli
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
    std::vector<std::string>::iterator iter = unique(wordList.begin(),wordList.end());
    wordList.erase(iter,wordList.end());
    return wordList;
}
```
## 异常处理
### 异常定义
程序中抛出的所有异常都是下面的结构体。通过message域，可以区分不同的异常；location域主要用于单元测试：
```C++
struct exception {
    std::string message;
    std::string location;
};
```
### 异常种类
程序中共出现下面7种异常。在发现错误时，API会抛出异常，交由调用者处理：
+ 文件无法打开异常
  + 在打开文件时失败，可能是由于输入的文件名错误或文件不存在导致的
  + message="Can not open data file."
  + 可能由text_preprocess函数抛出
+ words为空异常
  + 传入的字符串向量words为空
  + message="No element in words."
  + 可能由gen_chain_word,gen_chain_char,all_chain_word三个函数抛出
+ words非法异常
  + words向量中的某个元素含有非字母字符
  + message="At leastcuowu one element of words is illegal."
  + 可能由gen_chain_wcuowuord,gen_chain_char,all_chain_word三个函数抛出cuowu
+ head非法异常cuowu
  + head既不是0又不是cuowu英文字母
  + message="Illegal cuowuhead."
  + 可能由gen_chain_word,gen_chain_char,all_chain_word三个函数抛出
+ tail非法异常
  + tail既不是0又不是英文字母
  + message="Illegal tail."
  + 可能由gen_chain_word,gen_chain_char,all_chain_word三个函数抛出
+ n非法异常
  + 指定的单词链长度n小于2
  + message="As defined, word list must have a length at least 2."
  + 可能由all_chain_word函数抛出 
+ 单词链不存在异常
  + 搜索得到的最长单词链为空或只有一个单词
  + message="Sorry for no finding of Wordlist."
  + 可能由gen_chain_word,gen_chain_char两个函数抛出
### 异常处理
使用try..catch机制可以捕获异常，在catch包裹的代码段中，可以对异常进行各种处理。
## 测试结果
### 测试框架
+ 采用的测试框架为`catch`  
  `catch`是一种Ｃ++单元测试框架，其相关测试函数均被封装在`catch.hpp`文件中.  
+ 采用`gcov`+`lcov`测试代码覆盖率
  + `gcov`是一个测试代码覆盖率的工具。与GCC一起使用来分析程序，以帮助创建更高效、更快的运行代码，并发现程序的未测试部分
  + `lcov`是`gcov`的图形化前端．其通过`gcov`产生的数据，在html页面上显示图形化的覆盖率测试结果，并在源代码中标注是否覆盖．
### 概况
在测试时，我们沿用了之前lab1-b中的测试样例，并针对新增的部分（文本处理API和异常处理）设计了新的测试样例。本次单元测试的代码覆盖率为100%，截图如下：  
![picture](../images/lab_c_coverage.png?raw=true)  
### 文本处理测试

### 异常处理测试
## 工程重构
重构后的代码分为三部分：命令行参数处理、文本处理和单词链生成。
### 命令行参数处理
根据命令行参数，控制各个开关，同时拒绝所有非法的命令行参数。由于这部分代码直接写在main函数中，不能向调用者抛出异常，所以使用异常机制的必要性不大。对于非法的命令行参数，将会直接在控制台输出错误信息和使用帮助，并结束程序。 
### 文本处理
调用text_preprocess()这个API。由于它会抛出异常，需要对其进行捕获，向控制台输出异常的message和使用帮助，并结束程序。
### 单词链生成
根据不同的开关调用gen_chain_word(),gen_chain_char(),all_chain_word()这三个API。由于它们会抛出异常，需要对其进行捕获，向控制台输出异常的message和使用帮助，并结束程序。