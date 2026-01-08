#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r1, c1, r2, c2;

struct Node{
    int x,y,d;
    Node(int x, int y, int d) : x(x) , y(y) , d(d) {}
};

vector<pair<int,int>> walls;
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
bool checkRange(int x , int y){
    return x>= 0 && x <n && y>=0 && y < n ? true:false;
}

vector<vector<int>> eraseWallList;
void backtracking(vector<int> & v , int idx){
    if(v.size() == k){
        eraseWallList.push_back(v);
        return;
    }
    for(int i=idx;i<walls.size();i++){
        v.push_back(i);
        backtracking(v,i+1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) walls.push_back({i,j});
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    // Please write your code here.
    vector<int> tmp ={};
    backtracking(tmp,0);

    int result = 1000001;
    for(auto eraseWall : eraseWallList){
        int time = 0;
        vector<vector<int>> table = vector<vector<int>>(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 ) table[i][j] = 1;
            }
        }
        for(auto idx : eraseWall){
            table[walls[idx].first][walls[idx].second] = 0;
        }
        vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
        queue<Node> q;
        q.push(Node(r1,c1,0));
        visited[r1][c1] = true;

        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int d = q.front().d;
            q.pop();
            if(x == r2 && y == c2){
                time = d;
                break;
            }
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(checkRange(nx,ny) && table[nx][ny] != 1 && !visited[nx][ny]){
                    q.push(Node(nx,ny,d+1));
                    visited[nx][ny] = true;
                }
            }
        }
        
        if(time != 0 && result > time) result = time;
    }
    if(result == 1000001) cout<< -1;
    else cout<<result;
    return 0;
}
