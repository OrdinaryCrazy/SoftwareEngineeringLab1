#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
//大小写不敏感！
//异常处理
//边界条件
namespace sWN{

bool used(string next, vector<string> v){
    for(string s:v)
        if(s == next) return true;
    return false;
}
void request4(vector<string> w, int n){
    int size = w.size();
    //注意n>size的情况
    unordered_map<string, vector<string>> adj;
    set<vector<string>> a, b;
    for(string w1:w){
        for(string w2:w)
            if(w1.back() == w2[0]) adj[w1].push_back(w2);
        b.insert(vector<string> (1, w1));
    }

    for(int i=1; i<n; i++){
        a=b;
        b.clear();
        for(vector<string> v : a){
            string last = v.back();
            for(string next:adj[last])
                if(!used(next, v)){
                    v.push_back(next);
                    b.insert(v);
                    v.pop_back();
                }
        }
    }
    std::ofstream solutionOut("./solution.txt");
    solutionOut<<b.size();
    for(vector<string> v:b){
        solutionOut<<endl;
        for(string s:v)
            solutionOut<<s<<endl;
    }
    
}

}
