#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[10][10];
int result = 0;

void backtracking(vector<int> &v , vector<bool> visited){
    if(v.size() == n){
        int sum =0;
        for(int i=0;i<v.size();i++){
            sum += grid[i][v[i]];
        }
        if(sum > result) result = sum;
        return;
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
