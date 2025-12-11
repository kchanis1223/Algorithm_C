#include <iostream>
#include <vector>
#include<set>
using namespace std;

int N, M;


vector<vector<int>> result;
void backtracking(vector<int> &v){
    if(v.size() == M){
        set<int> s;
        for(auto i : v)s.insert(i);
        if(s.size() == M) result.push_back(v);
        return;
    }
    for(int i= v.empty()? 1 : v.back()+1; i<=N; i++){
        v.push_back(i);
        backtracking(v);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;
    vector<int> v = {};
    backtracking(v);
    for(auto i : result){
        for(auto j : i)cout<<j<<" ";
        cout<<endl;
    }

    // Please write your code here.

    return 0;
}
