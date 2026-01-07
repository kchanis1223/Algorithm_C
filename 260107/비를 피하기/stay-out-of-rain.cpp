#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, h, m;
int grid[100][100];

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

struct Node{
    int x, y, d;
    Node(int x,int y,int d) : x(x) , y(y) , d(d) {}
};

bool checkRange(int x , int y){
    return x>=0 && x <n && y >=0 && y <n ? true: false;
}

int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> result = vector<vector<int>>(n,vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] == 2){
                bool isValid = false;
                queue<Node> q;
                vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
                q.push(Node(i,j,0));
                visited[i][j] = true;

                while(!q.empty()){
                    int x = q.front().x;
                    int y = q.front().y;
                    int d = q.front().d;
                    q.pop();
                    if(grid[x][y] == 3){
                        result[i][j] = d;
                        isValid = true;
                        break;
                    }
                    for(int k=0;k<4;k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(checkRange(nx,ny) && !visited[nx][ny] && grid[nx][ny] != 1){
                            q.push(Node(nx,ny,d+1));
                            visited[nx][ny] = true;
                        }
                    }
                }
                if(!isValid) result[i][j] = -1;
            }
        }
    }
    for(auto i :result){
        for(auto j : i)cout<<j<<" ";
        cout<<endl;
    }
    



    return 0;
}
