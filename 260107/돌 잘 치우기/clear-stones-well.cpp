#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
bool checkRange(int x , int y){
    return x>=0 && x <n && y >=0 && y <n ? true:false;
}

int rockSize;
vector<vector<int>> removeList;
void backtracking(int idx, vector<int> & v){
    if(v.size() == m){
        removeList.push_back(v);
        return;
    }
    for(int i=idx;i<rockSize;i++){
        v.push_back(i);
        backtracking(i+1, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> k >> m;


    vector<pair<int,int>> points;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) points.push_back({i,j});
            rockSize = points.size();
        }
    }
    vector<int> tmp = {};
    backtracking(0,tmp);

    // for(auto i : removeList){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    int result = 0;
    for(auto removes : removeList){
        vector<vector<bool>> newGrid = vector<vector<bool>>(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) newGrid[i][j] = true;
            }
        }
        for(auto idx : removes){
            newGrid[points[idx].first][points[idx].second] = 0;
        }
        
        // cout<<"newGrid : "<<endl;
        // for(auto i : newGrid){
        //     for(auto j : i) cout<<j<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;

        vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(int i=0;i<k;i++){
            q.push({r[i],c[i]});
            visited[r[i]][c[i]] = true;
        }
    
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(checkRange(nx,ny) && !newGrid[nx][ny] && !visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }

        // cout<<"visited : "<<endl;
        // for(auto i : visited){
        //     for(auto j : i) cout<<j<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j] == true) cnt += 1;
            }
        }
        if(result < cnt) result = cnt; 
    }
    cout<<result;

    return 0;
}
