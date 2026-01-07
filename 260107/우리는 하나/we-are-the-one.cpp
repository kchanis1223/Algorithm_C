#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, u, d;
int grid[8][8];

vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};

vector<vector<pair<int,int>> > city_list;

void backtracking(vector<pair<int,int>> &v , int idx){
    if(v.size() == k){
        city_list.push_back(v);
        return;
    }
    for(int i= idx; i<n*n;i++){
        v.push_back({i/n , i%n});
        backtracking(v , i + 1);
        v.pop_back();
    }
}

bool checkRange(int x , int y){
    return x>=0 && x <n && y >=0 && y < n ? true: false;
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<pair<int,int>> tmp = {};
    backtracking(tmp, 0);
    
    int result = 0;
    for(auto citys : city_list){
        vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        for(auto p : citys){
            q.push({p.first,p.second});
            visited[p.first][p.second] = true;
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int height = grid[x][y];
            q.pop();

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int height_diff = abs(height - grid[nx][ny]) ;
                if(checkRange(nx,ny) && (u <= height_diff && height_diff <=d) && !visited[nx][ny] ){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        //cout<<"citys : ";
        //for(auto i : citys)cout<<i.first<<","<<i.second<<" / ";
        //cout<<endl;
        int cnt = 0;
        for(auto i : visited){
            for(auto j : i) {
                //cout<<j<<" ";
                if(j) cnt += 1;
            }
            //cout<<endl;
        }
        //cout<<endl;
        if(result < cnt) result = cnt;
    }
    cout<<result;

    // Please write your code here.

    return 0;
}
