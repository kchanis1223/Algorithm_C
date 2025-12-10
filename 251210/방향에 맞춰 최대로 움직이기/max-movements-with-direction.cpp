#include <iostream>
#include <vector>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;

vector<pair<int,int>> dirs = {
    {0,0},
    {-1,0},
    {-1,1},
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1},
    {-1,-1}
};

bool checkRange(int x , int y){
    return x>=0 && x <n && y>=0 && y<n ? true: false;
}
vector<pair<int,int>> FindNxt(int x , int y){
    vector<pair<int,int>> nxts = {};

    int dir_x = dirs[move_dir[x][y]].first;
    int dir_y = dirs[move_dir[x][y]].second;
    // cout<<"move_dir : "<<move_dir[x][y]<<endl;
    // cout<<"dir_x , dir_y = "<<dir_x<<","<<dir_y<<endl;
    for(int k = 1; k<=3; k++ ){
        int nxt_x = x + dir_x*k;
        int nxt_y = y + dir_y*k;
        //cout<<"nxt_x , nxt_y = "<<nxt_x<<","<<nxt_y<<endl;
        if(! checkRange(nxt_x,nxt_y)) continue;
        if(num[nxt_x][nxt_y] <= num[x][y] ) continue;
        nxts.push_back({nxt_x,nxt_y});
    }
    return nxts;
}

int maxCount = 0;
void backtracking(int x, int y, int count){
    vector<pair<int,int>> nxts = FindNxt(x,y);
    // cout<<"backtracking x,y = "<<x<<","<<y<<endl;
    // for(auto i : nxts) cout<<i.first<<","<<i.second<<" ";
    // cout<<endl;

    if(nxts.empty()){
        if(maxCount < count) maxCount = count;
        return;
    }
    for(int i=0;i<nxts.size();i++){
        backtracking(nxts[i].first, nxts[i].second, count+1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    
    // Please write your code here.
    backtracking(r-1,c-1,0);
    cout<<maxCount;
    return 0;
}
