#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r, c;

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
bool checkRange(int x , int y){
    return x>=0 && x <n && y >= 0 && y <n ? true:  false;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    int curValue = grid[r-1][c-1];
    int curX = r-1;
    int curY = c-1;
    for(int t=0;t<k;t++){
        //cout<<"cur :"<<curX<<","<<curY<<endl;
        vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({curX,curY});
        //visited[curX][curY] = true;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(checkRange(nx,ny) && grid[nx][ny] < curValue && !visited[nx][ny] ){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        // cout<<"visited :"<<endl;
        // for(auto i : visited){
        //     for(auto j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        int maxValue = 0;
        int nxtX = -1;
        int nxtY = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] && ! (i == curX && j == curY) ){
                    if(maxValue < grid[i][j]){
                        maxValue = grid[i][j];
                        nxtX = i;
                        nxtY = j;
                    }
                }
            }
        }
        if(nxtX == -1 || nxtY == -1) break;
        curX = nxtX;
        curY = nxtY;
        curValue = grid[nxtX][nxtY];
    }
    cout<<curX+1<<" "<<curY+1;
    // Please write your code here.

    return 0;
}
