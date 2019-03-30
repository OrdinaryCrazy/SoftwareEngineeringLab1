#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../CoreImplement.h"


TEST_CASE("standard test for lab1-b"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"END","OF","THE","WORLD"};
    std::vector<std::string> result;
    char head = 0;
    char tail = 0;
    
    int len = coreTest.gen_chain_word(input,result,head,tail);
    REQUIRE(len == 2);
    REQUIRE(result[0] == "the");
    REQUIRE(result[1] == "end");
}

TEST_CASE("case n test"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"WORD","LIST","DIGITAL"};
    std::set<std::vector<std::string>> result;
    char head = 0;
    char tail = 0;
    int n=2;
    
    int len = coreTest.all_chain_word(input,result,n,head,tail);
    REQUIRE(len == 2);
}
TEST_CASE("standard test for lab1 longest word"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox", "Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"};
    std::vector<std::string> result;
    char head = 0;
    char tail = 0;

    int len = coreTest.gen_chain_word(input,result,head,tail);
    REQUIRE(len == 4);
    REQUIRE(result[0] == "algebra");
    REQUIRE(result[1] == "apple");
    REQUIRE(result[2] == "elephant");
    REQUIRE(result[3] == "trick");
}

TEST_CASE("standard test for lab1 longest char"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox", "Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"};
    std::vector<std::string> result;
    char head = 0;
    char tail = 0;

    int len = coreTest.gen_chain_char(input,result,head,tail);
    REQUIRE(len == 2);
    REQUIRE(result[0] == "pseudopseudohypoparathyroidism");
    REQUIRE(result[1] == "moon");
}

TEST_CASE("standard test for lab1 longest word fixed head"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox", "Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"};
    std::vector<std::string> result;
    char head = 'e';
    char tail = 0;

    int len = coreTest.gen_chain_word(input,result,head,tail);
    REQUIRE(len == 2);
    REQUIRE(result[0] == "elephant");
    REQUIRE(result[1] == "trick");
}

TEST_CASE("standard test for lab1 longest word fixed tail"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox", "Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"};
    std::vector<std::string> result;
    char head = 0;
    char tail = 't';

    int len = coreTest.gen_chain_word(input,result,head,tail);
    REQUIRE(len == 3);
    REQUIRE(result[0] == "algebra");
    REQUIRE(result[1] == "apple");
    REQUIRE(result[2] == "elephant");
}

TEST_CASE("standard test for lab1 longest word fixed head & tail"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox", "Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"};
    std::vector<std::string> result;
    char head = 'a';
    char tail = 't';

    int len = coreTest.gen_chain_word(input,result,head,tail);
    REQUIRE(len == 3);
    REQUIRE(result[0] == "algebra");
    REQUIRE(result[1] == "apple");
    REQUIRE(result[2] == "elephant");
}

TEST_CASE("standard test for lab1 longest char fixed head"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox", "Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"};
    std::vector<std::string> result;
    char head = 'e';
    char tail = 0;

    int len = coreTest.gen_chain_char(input,result,head,tail);
    REQUIRE(len == 2);
    REQUIRE(result[0] == "elephant");
    REQUIRE(result[1] == "trick");
}

TEST_CASE("standard test for lab1 longest char fixed tail"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox", "Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"};
    std::vector<std::string> result;
    char head = 0;
    char tail = 't';

    int len = coreTest.gen_chain_char(input,result,head,tail);
    REQUIRE(len == 3);
    REQUIRE(result[0] == "algebra");
    REQUIRE(result[1] == "apple");
    REQUIRE(result[2] == "elephant");
}

TEST_CASE("standard test for lab1 longest char fixed head & tail"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"Algebra", "Apple", "Zoo", "Elephant", "Under", "Fox", "Dog", "Moon", "Leaf", "Trick", "Pseudopseudohypoparathyroidism"};
    std::vector<std::string> result;
    char head = 'a';
    char tail = 't';

    int len = coreTest.gen_chain_char(input,result,head,tail);
    REQUIRE(len == 3);
    REQUIRE(result[0] == "algebra");
    REQUIRE(result[1] == "apple");
    REQUIRE(result[2] == "elephant");
}

TEST_CASE("Different Head and Time Exceed A"){
    CoreImplement coreTest;
    std::ifstream inFile("./test/test_3.txt");
    if(!inFile){
        std::cout<<"Can not open data file."<<std::endl;
        exit(0);
    }
    std::string crudeString;    //从输入文件读取的原始内容
    std::string tempString;
    while(!inFile.eof()){
        inFile>>tempString;
        crudeString.append(tempString);
        crudeString.append(" ");
    }
    //通过数据预处理得到的字符串向量，作为各功能部件的数据接口输入
    std::vector<std::string> input = coreTest.preprocessingData(crudeString);
    std::vector<std::string> result;
    char head = 'a';
    //char tail = 0;

    int len = coreTest.gen_chain_char(input,result,head);
    REQUIRE(len == 25);
    REQUIRE(result[0] == "ab");
    REQUIRE(result[1] == "bc");
    REQUIRE(result[24] == "yz");
}

TEST_CASE("Different Head and Time Exceed B"){
    CoreImplement coreTest; 
    std::ifstream inFile("./test/test_3.txt");
    if(!inFile){
        std::cout<<"Can not open data file."<<std::endl;
        exit(0);
    }
    std::string crudeString;    //从输入文件读取的原始内容
    std::string tempString;
    while(!inFile.eof()){
        inFile>>tempString;
        crudeString.append(tempString);
        crudeString.append(" ");
    }
    //通过数据预处理得到的字符串向量，作为各功能部件的数据接口输入
    std::vector<std::string> input = coreTest.preprocessingData(crudeString);
    std::vector<std::string> result;
    char head = 'w';
    //char tail = 0;

    int len = coreTest.gen_chain_char(input,result,head);
    REQUIRE(len == 3);
    REQUIRE(result[0] == "wx");
    REQUIRE(result[1] == "xy");
    REQUIRE(result[2] == "yz");
}

TEST_CASE("Time Exceed "){
    CoreImplement coreTest;
    std::ifstream inFile("./test/test_4.txt");
    if(!inFile){
        std::cout<<"Can not open data file."<<std::endl;
        exit(0);
    }
    std::string crudeString;    //从输入文件读取的原始内容
    std::string tempString;
    while(!inFile.eof()){
        inFile>>tempString;
        crudeString.append(tempString);
        crudeString.append(" ");
    }
    //通过数据预处理得到的字符串向量，作为各功能部件的数据接口输入
    std::vector<std::string> input = coreTest.preprocessingData(crudeString);
    std::vector<std::string> result;
    char head = 'a';
    //char tail = 0;
    
    int len = coreTest.gen_chain_char(input,result,head);
    REQUIRE(len > 0);
    //REQUIRE(result[0] == "wx");
    //REQUIRE(result[1] == "xy");
    //REQUIRE(result[2] == "yz");
}

TEST_CASE("Time Exceed B"){
    CoreImplement coreTest; 
    std::ifstream inFile("./test/test_4.txt");
    if(!inFile){
        std::cout<<"Can not open data file."<<std::endl;
        exit(0);
    }
    std::string crudeString;    //从输入文件读取的原始内容
    std::string tempString;
    while(!inFile.eof()){
        inFile>>tempString;
        crudeString.append(tempString);
        crudeString.append(" ");
    }
    //通过数据预处理得到的字符串向量，作为各功能部件的数据接口输入
    std::vector<std::string> input = coreTest.preprocessingData(crudeString);
    std::vector<std::string> result;
    char head = 0;
    char tail = 0;

    int len = coreTest.gen_chain_char(input,result,head,tail);
    REQUIRE(len > 0);
    //REQUIRE(result[0] == "wx");
    //REQUIRE(result[1] == "xy");
    //REQUIRE(result[2] == "yz");
}
