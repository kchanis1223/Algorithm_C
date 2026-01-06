#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
int grid[50][50];

vector<vector<bool>> visited;
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
bool checkRange(int x , int y){
    return x>=0 && x <N && y >=0 && y <M ? true: false;
}

void dfs(int x , int y, int k, vector<vector<bool>> &visited){
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(checkRange(nx,ny) && grid[nx][ny] > k && !visited[nx][ny]){
            dfs(nx,ny,k,visited);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int result_k = 1;
    int result_h = 0;
    for(int k = 1; k<100; k++){
        int count = 0;
        visited = vector<vector<bool>>(N,vector<bool>(M,false));
        for(int i=0;i<N;i++){
            for(int j =0;j<M;j++){
                if(!visited[i][j] && grid[i][j] > k){
                    count += 1;
                    dfs(i,j,k,visited);
                }
            }
        }
        if(result_h < count) {
            result_h = count;
            result_k = k;
        }
    }
    cout<<result_k<<" "<<result_h;

    return 0;
}
