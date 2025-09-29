#include <iostream>
#include<vector>

using namespace std;

int n;
int grid[50][50];

bool checkRange(int x , int y){
    if(x >= 0 && x < n && y >=0 && y <n) return true;
    return false;
}

void explode(int x, int y, vector<vector<int>> & board){
    int range = grid[x][y] - 1;
    for(int i=x-range; i<= x+ range;i++){
        if(checkRange(i,y)) board[i][y] = 0;
    }
    for(int i=y-range; i<= y+ range;i++){
        if(checkRange(x,i)) board[x][i] = 0;
    }
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            if(board[n-1-j][i] != 0)v.push_back(board[n-1-j][i]);
        }
        while(v.size() != n) v.push_back(0);

        for(int j=0;j<n;j++){
            board[n-1-j][i] = v[j];
        }
    }
}
int calCount(vector<vector<int>>& board){
    vector<int> dx = {1,0};
    vector<int>dy = {0,1};

    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 0) continue;
            for(int k=0;k<2;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(checkRange(x,y) && board[x][y] == board[i][j]) {
                    count += 1;
                }
            }
        }
    }
    return count;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> grid_v;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            tmp.push_back(grid[i][j]);
        }
        grid_v.push_back(tmp);
    }

    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vector<vector<int>> board = grid_v;
            explode(i, j, board);
            // for(auto a : board){
            //     for(auto b : a){
            //         cout<<b<<" ";
            //     }
            //     cout<<endl;
            // }
            int count = calCount(board);
            //cout<<"count :"<<count<<endl;
            if(answer < count) answer = count;
        }
    }
    cout<<answer;

    // Please write your code here.

    return 0;
}
