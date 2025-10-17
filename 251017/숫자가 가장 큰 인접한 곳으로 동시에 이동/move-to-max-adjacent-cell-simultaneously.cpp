#include <iostream>
#include <vector>

using namespace std;

int n, m, t;
int a[20][20];
int r[400], c[400];

vector<vector<int>> grid;
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

bool checkRange(int x , int y){
    return x>=0 && x < n && y >= 0 && y < n ? true : false;
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    grid = vector<vector<int>>(n,vector<int>(n,0));
    vector<pair<int,int>> v;
    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i];
        v.push_back({r[i]-1,c[i]-1});
        grid[r[i]-1][c[i]-1] += 1;
    }

    for(int time = 0; time < t ; time ++){
        for(auto &p : v){
            grid[p.first][p.second] = 0;

            int nxtPx; int nxtPy;
            int maxValue = -1;
            for(int k = 0;k<4; k++){
                int nxtX = p.first + dx[k];
                int nxtY = p.second + dy[k];

                if(checkRange(nxtX,nxtY)){
                    if(maxValue < a[nxtX][nxtY]){
                        maxValue = a[nxtX][nxtY];
                        nxtPx = nxtX; nxtPy = nxtY;
                    }
                }
            }
            p.first = nxtPx; p.second = nxtPy;
        }
        for(auto p : v){
            grid[p.first][p.second] += 1;
        }
        vector<pair<int,int>> tmp;
        for(auto p : v){
            if(grid[p.first][p.second] == 1) tmp.push_back(p);
        }
        v= tmp;
        // cout<<"grid"<<endl;
        //     for(auto i : grid){
        //         for(auto j : i){
        //             cout<<j<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
    }
    
    int count = 0;
    for(auto i : grid){
        for(auto j : i){
            if(j == 1) count +=1;
        }
    }
    cout<<count;

    // Please write your code here.

    return 0;
}
