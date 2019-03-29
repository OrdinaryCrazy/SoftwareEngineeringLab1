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
