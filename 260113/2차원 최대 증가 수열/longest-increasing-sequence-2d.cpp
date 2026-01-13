#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[50][50];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    vector<vector<int>> dp = vector<vector<int>>(n,vector<int>(m,-1));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //cout<<"i,j : "<<i<<","<<j<<endl;
            if(i==0 && j==0) continue;
            int maxValue = -1;
            for(int ii =0; ii<i; ii++){
                for(int jj =0;jj<j;jj++){
                    if(grid[ii][jj] < grid[i][j] && maxValue < dp[ii][jj]) maxValue = dp[ii][jj];
                }
            }
            if(maxValue != -1) dp[i][j] = maxValue + 1;
        }
    }
    int result = -1;
    for(auto i : dp){
        for(auto j : i) if(result < j) result = j;//cout<<j<<" ";
        //cout<<endl;
    }
    cout<<result;
    return 0;
}
