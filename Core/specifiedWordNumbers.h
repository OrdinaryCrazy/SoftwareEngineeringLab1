#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<fstream>
#include<set>

namespace sWN{


std::set<std::vector<std::string>> result;
int error_flag=0;
bool used(std::string next, std::vector<std::string> v){
    for(std::string s:v)
        if(s == next) return true;
    return false;
}
void request4(std::vector<std::string> w, int n, char h=0, char t=0){
    if(n<2){
        std::cout<<"error: as defined, word list must have a length at least 2"<<std::endl;
        error_flag = 1;
        return;
    }
    int size = w.size();
    std::set<std::vector<std::string>> a,b;
    std::unordered_map<std::string, std::vector<std::string>> adj;
    if(h == 0){
        for(std::string w1:w){
            for(std::string w2:w)
                if(w1.back() == w2[0]) adj[w1].push_back(w2);
            b.insert(std::vector<std::string> (1, w1));
        }
    }
    else{
        for(std::string w1:w){
            for(std::string w2:w)
                if(w1.back() == w2[0]) adj[w1].push_back(w2);
            if(w1[0] == h) b.insert(std::vector<std::string> (1, w1));
        }
    }

    for(int i=1; i<n; i++){
        a=b;
        b.clear();
        for(std::vector<std::string> v : a){
            std::string last = v.back();
            for(std::string next:adj[last])
                if(!used(next, v)){
                    v.push_back(next);
                    b.insert(v);
                    v.pop_back();
                }
        }
    }
    if(t == 0){
        result = b;
    }

    else{
        result.clear();
        for(std::vector<std::string> v:b){
            std::string last = v.back();
            if(last.back() == t) result.insert(v); 
        }

    }
}

}