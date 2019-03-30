#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//#include "../include/Core.h"
#include "../CoreImplement.h"

TEST_CASE("standard test"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"END","OF","THE","WORLD"};
    std::vector<std::string> result;
    char head = 0;
    char tail = 0;
    
    int len = coreTest.gen_chain_word(input,result,head,tail);
    REQUIRE(len == 2);
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
