#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int grid[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp = vector<vector<int>>(n,vector<int>(n,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else if(i == 0) dp[i][j] = max(dp[i][j-1] , grid[i][j]);
            else if(j == 0) dp[i][j] = max(dp[i-1][j] , grid[i][j]);
            else{
                int minValue = min(dp[i][j-1], dp[i-1][j]);
                if(grid[i][j] < minValue) dp[i][j] = minValue;
                else dp[i][j] = grid[i][j];
            }
        }
    }
    cout<<dp[n-1][n-1];
    // Please write your code here.

    return 0;
}
