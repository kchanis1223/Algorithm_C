#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
bool checkRange(int x , int y){
    return x>=0 && x <n && y >= 0 && y <n ? true:  false;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];

    // Please write your code here.
    vector<vector<bool>> total = vector<vector<bool>>(n,vector<bool>(n,false));

    for(int t =0;t<k; t++){
        queue<pair<int,int>> q;
        q.push({r[t]-1,c[t]-1});

        vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(total[x][y] == true) break;
            
            visited[x][y] = true;

            for(int i=0;i<4;i++){
                int nx = x +dx[i];
                int ny = y +dy[i];
                if(checkRange(nx,ny) && grid[nx][ny] == 0 && !visited[nx][ny]) q.push({nx,ny});
            }
        }
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]) total[i][j] = true;
            }
        }
    }

    // for(auto i :  total){
    //     for(auto j : i) cout<<j<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    int count = 0;
    for(auto i :  total){
        for(auto j : i) if(j == true) count += 1;
    }
    cout<<count;
    return 0;
}
