#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

int N;
char grid[20][20];
int sx,sy;
int ex,ey;

vector<int> num_list;
vector<vector<int>> valids;
void backtracking(int idx, vector<int> &v){
    if(v.size() == 3){
        valids.push_back(v);
        return;
    }
    for(int i=idx; i<num_list.size(); i++){
        v.push_back(num_list[i]);
        backtracking(i+1,v);
        v.pop_back();
    }
}

int main(){ 
    cin >> N;

    map<int,pair<int,int>> m;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') {
                sx = i ; sy = j;
            }
            else if(grid[i][j] == 'E') {
                ex = i; ey= j;
            }
            else if(grid[i][j] != '.'){
                num_list.push_back(grid[i][j] - '0');
                m[grid[i][j] - '0'] = {i,j};
            }
        }
    }
    sort(num_list.begin(),num_list.end());

    // Please write your code here.
    if(num_list.size() >= 3) {
        vector<int> v= {};
        backtracking(0,v);
        
        int minD = INT_MAX;
        for(auto valid : valids){
            // for(auto i : valid) cout<<i<<" ";
            // cout<<endl;
            int d = 0;
            int cur_x = sx;
            int cur_y = sy;
            for(int i=0;i<3;i++){
                int nx = m[valid[i]].first;
                int ny = m[valid[i]].second;
                d += abs(nx - cur_x);
                d += abs(ny - cur_y);
                cur_x = nx;
                cur_y = ny;
                //cout<<"d :"<<d<<endl;
            }
            d += abs(ex - cur_x);
            d += abs(ey - cur_y);
            //cout<<" end distance : "<<d<<endl;
            if(d < minD) minD = d;
        }
        cout<<minD;
    }
    else cout<<-1;
    return 0;
}
