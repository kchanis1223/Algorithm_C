#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
int a[100][100];

void shift(int x1 ,int y1, int x2, int y2, vector<vector<int>>& grid){

    vector<int> v1; vector<int> v2; vector<int> v3; vector<int> v4;
    for(int i= x1; i<=x2;i++){
        for(int j= y1; j<=y2;j++){
            if(i == x1 && j <y2) v1.push_back(grid[i][j]);
            if(j == y2 && i <x2) v2.push_back(grid[i][j]);
            if(i == x2 && j >y1) v3.insert(v3.begin(),grid[i][j]);
            if(j == y1 && i >x1) v4.insert(v4.begin(),grid[i][j]);
        }
    }
    int tmp1 = v1.back(); v1.pop_back();
    int tmp2 = v2.back(); v2.pop_back();
    int tmp3 = v3.back(); v3.pop_back();
    int tmp4 = v4.back(); v4.pop_back();
    v1.insert(v1.begin(),tmp4);
    v2.insert(v2.begin(),tmp1);
    v3.insert(v3.begin(),tmp2);
    v4.insert(v4.begin(),tmp3);

    for(int i= x1; i<=x2;i++){
        for(int j= y1; j<=y2;j++){
            if(i == x1 && j <y2) grid[i][j] = v1[j-y1];
            if(j == y2 && i <x2) grid[i][j] = v2[i-x1];
            if(i == x2 && j >y1) grid[i][j] = v3[y2-j];
            if(j == y1 && i >x1) grid[i][j] = v4[x2-i];
        }
    }
}
bool checkRange(int x , int y){
    if(x < 0 || x >=n || y <0 || y >= m) return false;
    return true;
}
void applyAvg(int x1 ,int y1, int x2, int y2, vector<vector<int>>& grid){
    vector<vector<int>> tmp = grid;
    vector<int> dx = {0,0,0,-1,1};
    vector<int> dy = {0,-1,1,0,0};
    for(int i= x1; i<=x2;i++){
        for(int j= y1; j<=y2;j++){
            //if(i == x1 && j <y2) continue; if(j == y2 && i <x2) continue;  if(i == x2 && j >y1) continue; if(j == y1 && i >x1) continue;
            int sum =0;
            int count =0;
            for(int k=0;k<5;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(checkRange(x,y)) {
                    sum += grid[x][y];
                    count +=1;
                }
            }
            tmp[i][j] = sum/count ;
        }
    }
    grid = tmp;
}

int main() {
    vector<vector<int>> grid;
    vector<vector<int>> winds;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++){
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            tmp.push_back(a[i][j]);
        }
        grid.push_back(tmp);
    }

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        winds.push_back({r1,c1,r2,c2});
    }
    for(auto wind : winds){
        int x1 = wind[0]-1; int y1 = wind[1]-1; int x2 = wind[2]-1; int y2 = wind[3]-1;

        // cout<<"before :"<<endl;
        // for(int i= x1; i<=x2;i++){
        //     for(int j= y1; j<=y2;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        shift(x1,y1,x2,y2,grid);

        // cout<<"after shift :"<<endl;
        // for(int i= x1; i<=x2;i++){
        //     for(int j= y1; j<=y2;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        applyAvg(x1,y1,x2,y2,grid);
        
        // cout<<"after avg :"<<endl;
        // for(int i= x1; i<=x2;i++){
        //     for(int j= y1; j<=y2;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    for(int i= 0; i<n;i++){
        for(int j= 0; j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    // Please write your code here.

    return 0;
}
