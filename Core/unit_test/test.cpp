#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../CoreImplement.h"
#include "../exception.h" 
//=====================================================================================================================
//========== DEATH WARNING: NO CHANGE OR MOVE TO THE FOLLOWING CODE WHICH WILL CAUSE SEGMENTATION FAULT ===============
//=====================================================================================================================

#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>   //for EXIT_SUCCESS 
TEST_CASE("Time Exceed "){
    CoreImplement coreTest;
    std::vector<std::string> input = coreTest.text_preprocess("./test/test_4.txt");
    std::vector<std::string> result;
    char head = 'a';
    int len;

    pid_t pid = fork();
    int status = 0;
    if(pid == 0){
        len = coreTest.gen_chain_char(input,result,head);
        REQUIRE(len > 0);
        exit(EXIT_SUCCESS);
    }
    else
        wait(&status);
}
TEST_CASE("Time Exceed B"){
    CoreImplement coreTest; 
    std::vector<std::string> input = coreTest.text_preprocess("./test/test_4.txt");
    std::vector<std::string> result;
    char head = 0;
    char tail = 0;
    int len;

    pid_t pid = fork();
    int status = 0;
    if(pid == 0){
        len = coreTest.gen_chain_char(input,result,head,tail);
        REQUIRE(len > 0);
        exit(EXIT_SUCCESS);
    }
    else
        wait(&status);
}

//=====================================================================================================================
//============================================= DEATH WARNING END =====================================================
//=====================================================================================================================

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
    
    int len = coreTest.all_chain_word(input,result,n,head,tail);
    REQUIRE(len == 2);
}

TEST_CASE("specifiy word numbers--specify head and tail"){
    CoreImplement coreTest;
    std::vector<std::string> input = {"WORD","LIST","DIGITAL"};
    std::set<std::vector<std::string>> result;
    char head = 'w';
    char tail = 'l';
    int n=2;

    int len = coreTest.all_chain_word(input, result, n, head, tail);
    REQUIRE(len == 1);
    auto list = *result.begin();
    REQUIRE(list[0] == "word");
    REQUIRE(list[1] == "digital");
    
    
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
    std::vector<std::string> input = coreTest.text_preprocess("./test/test_3.txt");
    std::vector<std::string> result;
    char head = 'a';
    int len = coreTest.gen_chain_char(input,result,head);
    REQUIRE(len == 25);
    REQUIRE(result[0] == "ab");
    REQUIRE(result[1] == "bc");
    REQUIRE(result[24] == "yz");
}

TEST_CASE("Different Head and Time Exceed B"){
    CoreImplement coreTest; 
    std::vector<std::string> input = coreTest.text_preprocess("./test/test_3.txt");
    std::vector<std::string> result;
    char head = 'w';
    int len = coreTest.gen_chain_char(input,result,head);
    REQUIRE(len == 3);
    REQUIRE(result[0] == "wx");
    REQUIRE(result[1] == "xy");
    REQUIRE(result[2] == "yz");
}

TEST_CASE("right filename in text_preprocess"){
    CoreImplement coreTest;
    bool error=false;
    std::vector<std::string> result;
    try{
        result=coreTest.text_preprocess("./test/test_2.txt");
    }
    catch(expt::exception ex){
        error=true;
    }
    REQUIRE(!error);
    REQUIRE(8==result.size());
    REQUIRE(result[0]=="ab");
    REQUIRE(result[1]=="add");
    REQUIRE(result[2]=="bieiojiosjdfc");
    REQUIRE(result[3]=="biufd");
    REQUIRE(result[4]=="cd");
    REQUIRE(result[5]=="d");
    REQUIRE(result[6]=="daa");
    REQUIRE(result[7]=="dcfaswc");
}
TEST_CASE("wrong filename in text_preprocess"){
    CoreImplement coreTest;
    bool error=false;
    try{
        coreTest.text_preprocess("./test/test_.txt");
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Can not open data file.");
        REQUIRE(ex.location=="text_preprocess");
    }
    REQUIRE(error);
} 

TEST_CASE("empty words in gen_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {};
        std::vector<std::string> result;
        coreTest.gen_chain_word(input,result,0,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="No element in words.");
        REQUIRE(ex.location=="gen_chain_word");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal element of words in gen_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEM0N","ORANGE","STRAWBERRY"};
        std::vector<std::string> result;
        coreTest.gen_chain_word(input,result,0,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="At least one element of words is illegal.");
        REQUIRE(ex.location=="gen_chain_word");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal head in gen_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEMoN","ORANGE","STRAWBERRY"};
        std::vector<std::string> result;
        coreTest.gen_chain_word(input,result,1,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Illegal head.");
        REQUIRE(ex.location=="gen_chain_word");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal tail in gen_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEMoN","ORANGE","STRAWBERRY"};
        std::vector<std::string> result;
        coreTest.gen_chain_word(input,result,0,1);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Illegal tail.");
        REQUIRE(ex.location=="gen_chain_word");
    }
    REQUIRE(error);
} 

TEST_CASE("empty words in gen_chain_char"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {};
        std::vector<std::string> result;
        coreTest.gen_chain_char(input,result,0,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="No element in words.");
        REQUIRE(ex.location=="gen_chain_char");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal element of words in gen_chain_char"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEM0N","ORANGE","STRAWBERRY"};
        std::vector<std::string> result;
        coreTest.gen_chain_char(input,result,0,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="At least one element of words is illegal.");
        REQUIRE(ex.location=="gen_chain_char");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal head in gen_chain_char"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEMoN","ORANGE","STRAWBERRY"};
        std::vector<std::string> result;
        coreTest.gen_chain_char(input,result,1,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Illegal head.");
        REQUIRE(ex.location=="gen_chain_char");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal tail in gen_chain_char"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEMoN","ORANGE","STRAWBERRY"};
        std::vector<std::string> result;
        coreTest.gen_chain_char(input,result,0,1);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Illegal tail.");
        REQUIRE(ex.location=="gen_chain_char");
    }
    REQUIRE(error);
} 

TEST_CASE("empty words in all_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {};
        std::set<std::vector<std::string>> result;
        coreTest.all_chain_word(input,result,2,0,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="No element in words.");
        REQUIRE(ex.location=="all_chain_word");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal element of words in all_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEM0N","ORANGE","STRAWBERRY"};
        std::set<std::vector<std::string>> result;
        coreTest.all_chain_word(input,result,2,0,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="At least one element of words is illegal.");
        REQUIRE(ex.location=="all_chain_word");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal head in all_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEMoN","ORANGE","STRAWBERRY"};
        std::set<std::vector<std::string>> result;
        coreTest.all_chain_word(input,result,2,1,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Illegal head.");
        REQUIRE(ex.location=="all_chain_word");
    }
    REQUIRE(error);
} 
TEST_CASE("illegal tail in all_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEMoN","ORANGE","STRAWBERRY"};
        std::set<std::vector<std::string>> result;
        coreTest.all_chain_word(input,result,2,0,1);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Illegal tail.");
        REQUIRE(ex.location=="all_chain_word");
    }
    REQUIRE(error);
} 
TEST_CASE("n<2 in all_chain_word"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEMoN","ORANGE","STRAWBERRY"};
        std::set<std::vector<std::string>> result;
        coreTest.all_chain_word(input,result,1,0,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="As defined, word list must have a length at least 2.");
        REQUIRE(ex.location=="all_chain_word");
    }
    REQUIRE(error);
} 
TEST_CASE("No word list found in search"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE"};
        std::vector<std::string> result;
        coreTest.gen_chain_word(input,result,0,0);
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Sorry for no finding of Wordlist.");
        REQUIRE(ex.location=="search");
    }
    REQUIRE(error);
} 
TEST_CASE("No word list found in printSolution"){
    CoreImplement coreTest;
    bool error=false;
    try{
        std::vector<std::string> input = {"APPLE","LEMoN","ORANGE","STRAWBERRY"};
        std::vector<std::string> result;
        coreTest.gen_chain_word(input,result,'o','e');
    }
    catch(expt::exception ex){
        error=true;
        REQUIRE(ex.message=="Sorry for no finding of Wordlist.");
        REQUIRE(ex.location=="printSolution");
    }
    REQUIRE(error);
} 