#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];

vector<vector<bool>> visited;
bool checkRange(int x, int y){
    return x>=0 && x <n && y >= 0 &&y < n ? true :false;
}
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

int pCount = 0;
void dfs(int x , int y, vector<vector<bool>> & visited){
    visited[x][y] = true;
    pCount += 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(checkRange(nx,ny) && grid[nx][ny] && !visited[nx][ny] ) dfs(nx,ny,visited);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int vCount =0;
    vector<int> pCounts;
    visited = vector<vector<bool>>(n,vector<bool>(n,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if( grid[i][j] && !visited[i][j]){
                pCount = 0;

                vCount += 1;
                dfs(i,j,visited);
                pCounts.push_back(pCount);
            }
        }
    }

    cout<<vCount<<endl;
    sort(pCounts.begin(),pCounts.end());
    for(auto i : pCounts) cout<<i<<endl;

    // Please write your code here.

    return 0;
}
