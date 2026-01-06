#include <iostream>
#include <vector>
using namespace std;

int n;
int grid[100][100];

vector<vector<bool>> visited;
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
bool checkRange(int x , int y){
    return x>=0 && x <n && y >=0 && y <n ? true: false;
}

int count =0;
void dfs(int x, int y , int value, vector<vector<bool>> & visited){

    visited[x][y] = true;
    count += 1;
    for(int i=0;i<4;i++){
        int nx = x +dx[i];
        int ny = y +dy[i];
        if(checkRange(nx,ny) && grid[nx][ny] == value && !visited[nx][ny]) dfs(nx,ny,value,visited);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    visited = vector<vector<bool>>(n,vector<bool>(n,false));
    int result_n = 0;
    int result_count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                int value = grid[i][j];
                count = 0;
                dfs(i,j,value,visited);
                if(count >= 4) result_n +=1;
                if(result_count < count) result_count = count;
            }
        }
    }
    cout<<result_n<<" "<<result_count;

    return 0;
}
