#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int A[10][10];

int result = INT_MAX;

void backtracking(int idx, int count, int cost, vector<bool> &visited, vector<int> &v){
    if(count == n){
        if(idx != 0) return;
        // for(auto i : v) cout<<i<<" ";
        // cout<<endl;
        if(result > cost) result = cost;
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i] && A[idx][i] != 0){
            visited[i] = true;
            v.push_back(i);
            backtracking(i,count+1,cost+A[idx][i], visited, v);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector<bool> visited = vector<bool>(n,false);
    vector<int> v ={};
    backtracking(0,0,0,visited,v);
    cout<<result;

    return 0;
}
