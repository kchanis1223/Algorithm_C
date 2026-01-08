#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];

struct Node{
    int x,y,d;
    Node(int x, int y, int d) : x(x) , y(y) , d(d) {}
};

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
bool checkRange(int x , int y){
    return x>= 0 && x <n && y>=0 && y < n ? true:false;
}

int main() {
    cin >> n >> k;

    queue<Node> q;
    vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
    vector<vector<int>> result = vector<vector<int>>(n,vector<int>(n,-1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2){
                q.push(Node(i,j,0));
                visited[i][j] = true;
            }
            if(grid[i][j] == 1){
                result[i][j] = -2;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        result[x][y] = d;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(checkRange(nx,ny) && grid[nx][ny] == 1 && !visited[nx][ny]){
                q.push(Node(nx,ny,d+1));
                visited[nx][ny] = true;
            }
        }
    }

    for(auto i : result){
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }


    // Please write your code here.

    return 0;
}
