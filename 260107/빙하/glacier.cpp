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
bool checkMelting(int x, int y){
    bool isMelt = false;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(checkRange(nx,ny) && a[nx][ny] == 1) continue;

        bool isIsolate = true;
        vector<vector<bool>> visited = vector<vector<bool>>(N,vector<bool>(M,false));
        queue<pair<int,int>> q;
        q.push({nx,ny});

        while(!q.empty()){
            int qx = q.front().first;
            int qy = q.front().second;
            q.pop();
            if(qx == 0 || qx == N-1 || qy == 0 || qy == M-1){
                isIsolate = false;
                break;
            }
            for(int j=0;j<4;j++){
                int nqx = qx + dx[j];
                int nqy = qy + dy[j];
                if(checkRange(nqx,nqy) && a[nqx][nqy] == 0 && !visited[nqx][nqy]){
                    q.push({nqx,nqy});
                    visited[nqx][nqy] = true;
                }
            }
        }
    
        if(isIsolate) continue;

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

    vector<int> remainings = {init};
    for(int t = 0; t<=100; t++){
        vector<vector<bool>> grid = vector<vector<bool>>(N,vector<bool>(M,false));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(a[i][j] == 1) grid[i][j] = true;
            }
        }

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
