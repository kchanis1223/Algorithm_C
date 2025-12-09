#include <iostream>
#include <vector>
using namespace std;

int K, N;

vector<vector<int>> total_l;

void backtracking(vector<int> &v){

    if(v.size() == N){
        total_l.push_back(v);
        return;
    }

    for(int select = 1; select <= K; select ++){
        if( v.size() >= 2 && v[v.size()-2] == select && v.back() == select) continue;
        v.push_back(select);
        backtracking(v);
        v.pop_back();
    }
}

int main() {
    cin >> K >> N;
    vector<int> v = {};
    backtracking(v);
    for(auto i : total_l){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    // Please write your code here.

    return 0;
}
