#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[100][100];

vector<int> dx = {1,0};
vector<int> dy = {0,1};

bool isSuccess = false;

bool checkRange(int x , int y){
    return x>=0 && x <n && y >=0 &&y <m ? true :  false;
}

void dfs(int x, int y, vector<vector<bool>> & visited){
    visited[x][y] = true;
    if(x == n-1 && y == m-1){
        isSuccess = true;
        return;
    }
    for(int i=0;i<2;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(checkRange(nx,ny) && grid[nx][ny] && !visited[nx][ny] ) dfs(nx,ny, visited) ;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(m,false));
    dfs(0,0,visited);
    cout<<isSuccess;
    // Please write your code here.

    return 0;
}
