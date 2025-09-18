#include <iostream>
#include <vector>

using namespace std;

void ReverseClockWise(vector<vector<int>> &grid, vector<int> info){
    vector<vector<int>> tmp = grid;
    
    int m1= info[2] ; int m2 = info[3]; int m3 = info[4]; int m4 = info[5];
    int curX = info[0]-1; int curY = info[1]-1;
    int prev_value = -1;
    for(int i=0; i<m1; i++){
        int cur_value = grid[curX][curY];
        tmp[curX][curY] = prev_value;
        prev_value = cur_value;
        curX -= 1;
        curY += 1;
    }
    for(int i=0; i<m2; i++){
        int cur_value = grid[curX][curY];
        tmp[curX][curY] = prev_value;
        prev_value = cur_value;
        curX -= 1;
        curY -= 1;
    }
    for(int i=0; i<m3; i++){
        int cur_value = grid[curX][curY];
        tmp[curX][curY] = prev_value;
        prev_value = cur_value;
        curX += 1;
        curY -= 1;
    }
    for(int i=0; i<m4; i++){
        int cur_value = grid[curX][curY];
        tmp[curX][curY] = prev_value;
        prev_value = cur_value;
        curX += 1;
        curY += 1;
    }
    tmp[curX][curY] = prev_value;
    grid = tmp;
}
void ClockWise(vector<vector<int>> &grid, vector<int> info){
    vector<vector<int>> tmp = grid;
    
    int m1= info[2] ; int m2 = info[3]; int m3 = info[4]; int m4 = info[5];
    int curX = info[0]-1; int curY = info[1]-1;
    int prev_value = -1;
    for(int i=0; i<m4; i++){
        int cur_value = grid[curX][curY];
        tmp[curX][curY] = prev_value;
        prev_value = cur_value;
        curX -= 1;
        curY -= 1;
    }
    for(int i=0; i<m3; i++){
        int cur_value = grid[curX][curY];
        tmp[curX][curY] = prev_value;
        prev_value = cur_value;
        curX -= 1;
        curY += 1;
    }
    for(int i=0; i<m2; i++){
        int cur_value = grid[curX][curY];
        tmp[curX][curY] = prev_value;
        prev_value = cur_value;
        curX += 1;
        curY += 1;
    }
    for(int i=0; i<m1; i++){
        int cur_value = grid[curX][curY];
        tmp[curX][curY] = prev_value;
        prev_value = cur_value;
        curX += 1;
        curY -= 1;
    }
    tmp[curX][curY] = prev_value;
    grid = tmp;
}

int main() {
    // Please write your code here.
    int N;
    cin>>N;
    vector<vector<int>> grid;
    for(int i=0;i<N;i++){
        vector<int> tmp;
        for(int j=0;j<N;j++){
            int input;
            cin>>input;
            tmp.push_back(input);
        }
        grid.push_back(tmp);
    }
    int r,c,m1,m2,m3,m4,dir;
    cin>>r>>c>>m1>>m2>>m3>>m4>>dir;

    // vector<int> v1; vector<int> v2; vector<int> v3; vector<int> v4;
    // int curX = r-1; int curY = c-1;
    // for(int i=0; i<m1; i++){
    //     v1.push_back(grid[curX][curY]);
    //     curX -= 1;
    //     curY += 1;
    // }
    // for(int i=0; i<m2; i++){
    //     v2.push_back(grid[curX][curY]);
    //     curX -= 1;
    //     curY -= 1;
    // }
    // for(int i=0; i<m3; i++){
    //     v3.push_back(grid[curX][curY]);
    //     curX += 1;
    //     curY -= 1;
    // }
    // for(int i=0; i<m4; i++){
    //     v4.push_back(grid[curX][curY]);
    //     curX += 1;
    //     curY += 1;
    // }
    if (dir == 0 )ReverseClockWise(grid,{r,c,m1,m2,m3,m4});
    else ClockWise(grid,{r,c,m1,m2,m3,m4});

    for(auto i : grid){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    // for(auto i : v1){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i : v2){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i : v3){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i : v4){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    return 0;
}