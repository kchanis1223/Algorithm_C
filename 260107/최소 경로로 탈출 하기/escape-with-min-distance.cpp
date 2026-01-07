#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int a[100][100];

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

bool checkRange(int x , int y){
    return x>=0 && x <n && y >=0 && y <m ? true: false;
}

struct Node{
    int x;
    int y;
    int d;
    Node(int X, int Y, int D) : x(X), y(Y), d(D) {}
};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.

    bool isExit = false;

    vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(m,false));
    queue<Node> q;
    q.push(Node(0,0,0));
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();

        if(x ==n-1 && y == m-1){
            isExit = true;
            cout<<d;
            break;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(checkRange(nx,ny) && !visited[nx][ny] && a[nx][ny] == 1){
                q.push(Node(nx,ny,d+1));
                visited[nx][ny] = true;
            }
        }
    }
    if(!isExit) cout<<-1;
    return 0;
}
