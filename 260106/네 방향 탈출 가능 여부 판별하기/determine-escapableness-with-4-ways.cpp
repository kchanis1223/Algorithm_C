#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int a[100][100];

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};
bool checkRange(int x , int y) {
    return x>=0 && x < n && y >=0 &&y < n ? true :false;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    bool isSuccess = false;
    vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;

        if(x == n-1 && y == n-1){
            isSuccess = true;
            break;
        }

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(checkRange(nx,ny) && a[nx][ny] && !visited[nx][ny]) q.push({nx,ny});
        }
    }
    isSuccess ? cout<< 1 : cout<<0;
    return 0;
}
