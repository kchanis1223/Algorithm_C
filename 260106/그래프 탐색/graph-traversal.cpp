#include <iostream>
#include <vector>

using namespace std;

int n, m;
int from[10000], to[10000];
vector<vector<bool>> table;
vector<bool> visited;
void dfs(int idx){
    visited[idx] = true;
    for(int i=1;i<=n;i++){
        if(!visited[i] && table[idx][i]) dfs(i);
    }
}

int main() {
    cin >> n >> m;

    table = vector<vector<bool>>(n+1,vector<bool>(n+1,false));
    visited = vector<bool>(n+1,false);
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
        table[from[i]][to[i]] = true;
        table[to[i]][from[i]] = true;
    }
    
    dfs(1);
    int count = 0;
    // for(auto i : visited) cout<<i<<" ";
    // cout<<endl;
    for(auto i : visited) if(i == true) count +=1;
    cout<<count-1;
    // Please write your code here.

    return 0;
}
