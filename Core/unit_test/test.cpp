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

TEST_CASE("specifiy word numbers--basic"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"WORD","LIST","DIGITAL"};
    std::set<std::vector<std::string>> result;
    char head = 0;
    char tail = 0;
    int n=2;
    int error_flag=0;
    
    int len = coreTest.all_chain_word(input,result,n,error_flag,head,tail);
    REQUIRE(len == 2);
}

TEST_CASE("specifiy word numbers--specify head and tail"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"WORD","LIST","DIGITAL"};
    std::set<std::vector<std::string>> result;
    char head = 'w';
    char tail = 'l';
    int n=2;
    int error_flag=0;

    int len = coreTest.all_chain_word(input, result, n, error_flag, head, tail);
    REQUIRE(len == 1);
    auto list = *result.begin();
    REQUIRE(list[0] == "word");
    REQUIRE(list[1] == "digital");
    
    
}

TEST_CASE("specifiy word numbers--error"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"WORD","LIST","DIGITAL"};
    std::set<std::vector<std::string>> result;
    char head = 0;
    char tail = 0;
    int n=1;
    int error_flag=0;
    
    int len = coreTest.all_chain_word(input,result,n,error_flag,head,tail);
    REQUIRE(error_flag == 1);
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
    //REQUIRE(result[0] == "pseudopseudohypoparathyroidism");
    //REQUIRE(result[1] == "moon");
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
