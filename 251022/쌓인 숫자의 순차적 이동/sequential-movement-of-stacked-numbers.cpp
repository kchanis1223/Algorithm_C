#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

int n, m;
int grid[20][20];
int move_nums[100];

map<int,vector<int>> mIdx;  // key:num , value: 위치 {x,y}
vector<vector<vector<int>>> table;

vector<int> dx = {-1,-1,-1,0,0,1,1,1};
vector<int> dy = {-1,0,1,-1,1,-1,0,1};

void changeTable(int x, int y, int t, int nxtX, int nxtY){
    vector<int> remain;
    vector<int> move;
    vector<int> v = table[x][y];
    for(int i = 0; i < v.size();i++){
        if (i < t) remain.push_back(v[i]);
        else move.push_back(v[i]);
    }
    table[x][y] = remain;
    for(auto i : move){
        mIdx[i] = {nxtX,nxtY,int(table[nxtX][nxtY].size())};
        table[nxtX][nxtY].push_back(i);
    }
    remain.empty() ? grid[x][y] = -1 : grid[x][y] = *max_element(remain.begin(),remain.end());
    grid[nxtX][nxtY] = *max_element(table[nxtX][nxtY].begin(),table[nxtX][nxtY].end());
}

bool checkRange(int x , int y){
    return x>=0 && x < n && y >=0 && y < n ? true:false;
}

int main() {
    cin >> n >> m;

    table = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>()));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            mIdx[grid[i][j]] = {i,j,0};
            table[i][j].push_back(grid[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> move_nums[i];
    }

    // Please write your code here.
    for(int i =0 ; i < m ; i++){
        int num = move_nums[i];
        int x = mIdx[num][0];
        int y = mIdx[num][1];
        int t = mIdx[num][2];

        int nxtX,nxtY;
        int maxNum = -1;
        for(int k = 0 ; k <8; k++){
            if(!checkRange(x+dx[k],y+dy[k])) continue;
            if(maxNum < grid[x + dx[k]][y + dy[k]]){
                maxNum = grid[x+dx[k]][y+dy[k]];
                nxtX = x + dx[k];
                nxtY = y + dy[k];
            }
        }
        if(maxNum == -1)continue;
        changeTable(x,y,t,nxtX,nxtY);
        //cout<<"table [2][0]"<<endl;
        //cout<<table[2][0][0]<<" "<<table[2][0][1]<< " "<<table[2][0][2]<<endl;
        // cout<<"grid : "<<endl;
        // for(int i=0;i<3;i++){
        //     for(int j = 0 ; j <3;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
    }

    for(int i=0;i<n;i++){
        for(int j = 0;j <n;j++){
            if(table[i][j].size() == 0){
                cout<<"None"<<endl;
                continue;
            }
            for(int k = table[i][j].size()-1 ; k>=0;k--){
                cout<<table[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
