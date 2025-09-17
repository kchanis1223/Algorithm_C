#include <iostream>
#include <vector>
using namespace std;

int n, m;
int grid[200][200];

bool checkRange(int x , int y, vector<pair<int,int>> block){
    bool isValid = true;
    for(auto &p : block){
        if (x+p.first < 0 || x+p.first >=n || y +p.second < 0 || y + p.second >=m) isValid = false;
    }
    return isValid;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<pair<int,int>>> blocks = { 
        {{0,0},{0,1},{1,0}}, {{0,0},{0,1},{-1,0}}, {{0,0},{0,-1},{1,0}}, {{0,0},{0,-1},{-1,0}},
        {{0,0},{0,-1},{0,1}}, {{0,0},{-1,0},{1,0}}
    };

    int result = 0;
    for(int x = 0;x<n;x++){
        for(int y =0;y<m;y++){
            int sum = 0;
            for(auto &block : blocks){
                if( checkRange(x,y,block) ){
                    int blockSum = 0;
                    for(auto &p : block){
                        blockSum += grid[x + p.first][y +p.second];
                    }
                    if(blockSum > sum) sum = blockSum;
                }
            }
            if(result < sum) result = sum;
        }
    }
    cout<<result;
    // Please write your code here.

    return 0;
}
