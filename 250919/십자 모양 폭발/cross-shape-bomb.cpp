#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[200][200];
int r, c;

bool checkRange(int x , int y){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}
int main() {
    cin >> n;
    vector<vector<int>> m;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            tmp.push_back(grid[i][j]);
        }
        m.push_back(tmp);
    }

    cin >> r >> c;
    r -=1; c-=1;
    int range = grid[r][c] - 1;
    for(int x = r - range; x<= r + range ; x++ ){
        if(checkRange(x,c)) m[x][c] = 0;
    }
    for(int y = c - range; y<= c + range ; y++ ){
        if(checkRange(r,y)) m[r][y] = 0;
    }

    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j =0;j<n;j++){
            if(m[n-1-j][i] != 0) v.push_back(m[n-1-j][i]);
        }
        while(v.size() < n) v.push_back(0);

        for(int j=0;j<n;j++){
            m[n-1-j][i] = v[j];
        }
    }

    for(auto i : m){
        for(auto j : i){
            cout<< j<<" ";
        }
        cout<<endl;
    }
    // Please write your code here.

    return 0;
}
