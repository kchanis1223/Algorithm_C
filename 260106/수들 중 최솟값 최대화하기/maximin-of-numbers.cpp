#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[10][10];

int result =0;
void backtracking(vector<int> v, vector<bool> visited){

    if(v.size() == n){
        int minNum = 10001;
        for(int i=0;i<v.size();i++){
            if(minNum > grid[i][v[i]]) minNum = grid[i][v[i]];
        }
        if(result < minNum) result = minNum;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            backtracking(v,visited);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> v = {};
    vector<bool> visited = vector<bool>(n,false);
    backtracking(v,visited);
    cout<<result;

    // Please write your code here.

    return 0;
}
