#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
int grid[20][20];

bool checkRange(int x , int y){
    return x >= 0 && x < n && y >= 0 && y < n ? true : false;
}

int main() {
    cin >> n >> m;

    map<int,pair<int,int>> hash;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            hash[grid[i][j]] = {i,j};
        }
    }
    
    for(int t =0; t<m; t++){
        for(auto i : hash){
            int value = i.first;
            //cout<<"value : "<<value<<endl;
            int x = i.second.first;
            int y = i.second.second;

            int maxNum = 0;
            int swapX, swapY;

            for(int u = -1 ; u <= 1; u++){
                for(int v = -1; v <= 1; v++){
                    if(u == 0 && v == 0) continue;

                    int nxtX = x + u ; int nxtY = y + v;
                    if(checkRange(nxtX,nxtY)){
                        if(maxNum < grid[nxtX][nxtY]){
                            maxNum = grid[nxtX][nxtY];
                            swapX = nxtX; swapY = nxtY;
                        }
                    }
                }
            }
            //cout<<"X,Y :"<<x<<","<<y<<endl;
            //cout<<"swapX,swapY :"<<swapX<<","<<swapY<<endl;
            swap(grid[x][y],grid[swapX][swapY]);
            hash[value] = {swapX,swapY}; hash[maxNum] = {x,y};

            // for(int i = 0;i < n; i++){
            //     for(int j = 0 ; j < n; j ++){
            //         cout<<grid[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
        }

    }
    //cout<<"==============="<<endl;
    for(int i = 0;i < n; i++){
        for(int j = 0 ; j < n; j ++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    // Please write your code here.

    return 0;
}
