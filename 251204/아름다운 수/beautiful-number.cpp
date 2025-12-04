#include <iostream>
#include <vector>

using namespace std;

int n;
int count;

void backtracking(vector<int> &v){
    if(v.size() > n) return;
    if(v.size() == n){
        count +=1;
        return;
    }
    for(int i=1;i<=4;i++){
        for(int j=0;j<i;j++){
            v.push_back(i);
        }
        backtracking(v);
        for(int j=0;j<i;j++){
            v.pop_back();
        }
    }
}

int main() {
    cin >> n;
    vector<int> v = {};
    backtracking(v);
    cout<<count;
    // Please write your code here.

    return 0;
}
