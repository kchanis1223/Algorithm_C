#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int a[200][200];
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

bool checkRange(int x , int y){
    return x>=0 && x <N && y >=0 && y < M ? true: false;
}

vector<vector<bool>> meltTable; // true가 닿으면 녹는 얼음

void ApplyMeltTable(vector<vector<bool>> grid){
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(i == 0 || i == N-1 || j == 0 || j ==M-1) {
                v.push_back({i,j});
                meltTable[i][j] = false;
                continue;
            }
        }
    }

    bool isMelt = false;
    vector<vector<bool>> visited = vector<vector<bool>>(N,vector<bool>(M,false));
    queue<pair<int,int>> q;
    for(auto p : v){
        q.push({p.first,p.second});
        visited[p.first][p.second] = true;
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx = x+ dx[k];
            int ny = y + dy[k];
            if(checkRange(nx,ny) && !grid[nx][ny] && !visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
    meltTable = visited;
}

bool checkMelting(int x, int y){
    bool isMelt = false;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!checkRange(nx,ny)) continue;
        if(a[nx][ny] == 1) continue;
        if(!meltTable[nx][ny]) continue;
        isMelt = true;
    
    }
    return isMelt;
}

int main() {
    cin >> N >> M;

    int init =0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) init += 1;
        }
    }

    meltTable = vector<vector<bool>>(N,vector<bool>(M,true));
    vector<int> remainings = {init};
    for(int t = 0; t<=100; t++){
        vector<vector<bool>> grid = vector<vector<bool>>(N,vector<bool>(M,false));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(a[i][j] == 1) grid[i][j] = true;
            }
        }
        ApplyMeltTable(grid);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(a[i][j] == 1 && checkMelting(i,j)){
                    grid[i][j] = false;
                }
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!grid[i][j]){
                    a[i][j] = 0;
                }
            }
        }
        int remain = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                //cout<<a[i][j]<<" ";
                if(a[i][j] == 1) remain += 1;
            }
            //cout<<endl;
        }
        //cout<<endl;

        //cout<<"t : "<<t<<" / remain :"<<remain<<endl;
        if(remain == 0) break;
        else remainings.push_back(remain);
    }
    //for(auto i : remainings) cout<<i<<" ";
    cout<<remainings.size()<<" "<<remainings.back();
    // Please write your code here.

    return 0;
}
