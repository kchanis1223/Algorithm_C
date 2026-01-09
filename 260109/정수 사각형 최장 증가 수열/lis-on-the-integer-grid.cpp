#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int grid[500][500];

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

bool checkRange(int x, int y){
    return x >=0 && x <= n && y >=0 && y < n ? true:false;
}
struct Node{
    int x,y,d;
    Node(int x, int y, int d) : x(x) , y(y), d(d) {}
};

int bfs(int x, int y){
    vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
    queue<Node> q;
    q.push(Node(x,y,1));
    visited[x][y] = true;

    int maxCount = 0;
    while(!q.empty()){
        bool isLast = true;
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(checkRange(nx,ny) && (grid[nx][nx] > grid[x][y] ) && !visited[nx][ny] ){
                isLast = false;
                q.push(Node(nx,ny,d+1));
                visited[nx][ny] = true;
            }
        }
        if(isLast && maxCount < d) maxCount = d; 
    }
    return maxCount;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    //vector<vector<int>> dp = vector<vector<int>>(n,vector<int>(n,0));

    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = bfs(i,j);
            if(result < cnt) result = cnt;
        }
    }
    cout<<result;
    return 0;
}
