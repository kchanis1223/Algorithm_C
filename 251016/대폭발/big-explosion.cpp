#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

int n, m, r, c;

bool checkRange(int x , int y){
    return (x >=0 && x < n && y >=0 && y < n )? true : false;
}

int main() {
    cin >> n >> m >> r >> c;

    // Please write your code here.
    //vector<vector<int>> grid = vector<vector<int>(n,vector<int>(n,0));
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    set<pair<int,int>> s;
    //grid[r-1][c-1] = 1;
    s.insert({r-1,c-1});

    for(int t = 1; t <= m ; t++){
        set<pair<int,int>> add_s;
        for(auto p: s){
            for(int k = 0 ; k <4 ; k++){
                int nxtX = p.first + pow(2,t-1)*dx[k];
                int nxtY = p.second + pow(2,t-1)*dy[k];
                if(checkRange(nxtX,nxtY)){
                    add_s.insert({nxtX,nxtY});
                }
            }
        }
        for(auto p : add_s){
            s.insert(p);
        }
    }
    cout<<s.size();
    return 0;
}
