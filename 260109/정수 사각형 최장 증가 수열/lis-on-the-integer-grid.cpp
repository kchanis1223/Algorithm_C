#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int grid[500][500];

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

bool checkRange(int x, int y){
    return x >=0 && x < n && y >=0 && y < n ? true:false;
}

vector<vector<int>> dp;

int dfs(int x, int y){
    if(dp[x][y] != 0) return dp[x][y];

    dp[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x +dx[i];
        int ny = y +dy[i];
        if(checkRange(nx,ny) && grid[nx][ny] < grid[x][y] ){
            dp[x][y] = max(dp[x][y], 1 + dfs(nx,ny));
        }
    }
    return dp[x][y];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    dp = vector<vector<int>>(n,vector<int>(n,0));

    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result = max(result, dfs(i,j));
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(result < dp[i][j]) result = dp[i][j];
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<result;

    return 0;
}
