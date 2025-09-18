#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
int a[100][100];
vector<vector<int>> grid;
vector<pair<int,int>> winds;

void applyWind(int idx , int dir){
    vector<int> v = grid[idx];
    if(dir == -1){
        int tmp = v.back();
        v.pop_back();
        v.insert(v.begin(),tmp);
    }
    else{
        int tmp = v[0];
        v.erase(v.begin());
        v.push_back(tmp);
    }
    grid[idx] = v;
}
bool isValid(int idx1, int idx2){
    for(int i=0;i<m;i++){
        if(grid[idx1][i] == grid[idx2][i]) return true;
    }
    return false;
}
void applyWindUp(int idx, int dir){
    applyWind(idx, dir);
    if(idx - 1 >=0 && isValid(idx, idx-1)){
        applyWindUp(idx-1,-dir);
    }
}
void applyWindDown(int idx, int dir){
    applyWind(idx, dir);
    if(idx + 1 <n && isValid(idx, idx+1)){
        applyWindDown(idx+1,-dir);
    }
}
int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            tmp.push_back(a[i][j]);
        }
        grid.push_back(tmp);
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        winds.push_back({r,(d == 'L'?-1:1)});
    }

    for(auto wind : winds){
        int idx = wind.first -1;
        int dir = wind.second; // -1이면 left 바람 
        applyWind(idx,dir);
        if(idx != 0) applyWindUp(idx-1,-dir);
        if(idx != n-1) applyWindDown(idx+1,-dir);

        // for(auto i : grid){
        //     for(auto j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    for(auto i : grid){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    // Please write your code here.

    return 0;
}
