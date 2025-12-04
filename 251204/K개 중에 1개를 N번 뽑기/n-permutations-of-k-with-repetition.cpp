#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> result;
int K;
int N;

void backtracking(vector<int>& v){
    if(v.size() == N){
        result.push_back(v);
        return;
    }

    for(int i=1;i<=K;i++){
        v.push_back(i);
        backtracking(v);
        v.pop_back();
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>K>>N;
    vector<int> v ={};
    backtracking(v);

    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}