#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int r1, c1, r2, c2;

vector<int> dx = {-1,-2,-2,-1,1,2,2,1};
vector<int> dy = {-2,-1,1,2,-2,-1,1,2};

bool checkRange(int x , int y){
    return x>=0 && x <n && y >=0 && y <n ? true: false;
}

struct Node{
    int x, y, d;
    Node(int x, int y, int d) : x(x) , y(y) , d(d) {}
};

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    bool isValid = false;

    vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
    queue<Node> q;
    q.push(Node(r1-1,c1-1,0));
    visited[r1-1][c1-1] = true;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        
        if(x == r2-1 && y == c2-1){
            cout<<d;
            isValid = true;
            break;
        }
        for(int i=0;i<8;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(checkRange(nx,ny) && !visited[nx][ny]){
                q.push(Node(nx,ny,d+1));
                visited[nx][ny] = true;
            }
        }
    }
    if(!isValid) cout<<-1;

    return 0;
}
