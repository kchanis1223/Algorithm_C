#include <iostream>
#include <vector>

using namespace std;

int n;
int max_count = 0;
int grid[20][20];

vector<pair<int,int>> bombs;

vector<vector<pair<int,int>>> shapes = {
    {{-2,0},{-1,0},{1,0},{2,0}},
    {{-1,0},{1,0},{0,-1},{0,1}},
    {{-1,-1},{-1,1},{1,-1},{1,1}}
};
bool checkRange(int x , int y){
    return x >= 0 && x < n && y >= 0 && y < n ? true : false;
}

void backtracking(int k, vector<vector<int>> g){
    if(k == bombs.size()){
        int count = 0;
        for(auto &i: g){
            for(auto &j: i){
                if(j == 1) count +=1;
            }
        }
        if(max_count < count) max_count = count;
        return;
    }

    for(auto shape: shapes){
        int x = bombs[k].first;
        int y = bombs[k].second;
        vector<vector<int>> new_g = g;
        for(int i = 0; i<shape.size(); i++){
            if(checkRange(x+shape[i].first, y + shape[i].second)){
                new_g[x+shape[i].first][y + shape[i].second] = 1;
            }
        }
        // for(auto &i: new_g){
        //     for(auto &j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        backtracking(k+1,new_g);
    }
}

int main() {
    cin >> n;

    vector<vector<int>> G;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            tmp.push_back(grid[i][j]);
            if(grid[i][j] == 1) bombs.push_back({i,j});
        }
        G.push_back(tmp);
    }
    backtracking(0,G);
    cout<< max_count;
    // Please write your code here.

    return 0;
}
