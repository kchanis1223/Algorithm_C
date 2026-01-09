#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int grid[100][100];

bool checkRange(int x, int y){
    return x >=0 && x <= n && y >=0 && y < n ? true:false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    vector<vector<int>> dp = vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0) {dp[i][j] = grid[i][j]; continue;}
            int maxValue = max( (checkRange(i-1,j)? dp[i-1][j] : 0) , (checkRange(i,j-1)? dp[i][j-1] : 0) );
            if(grid[i][j] < maxValue) dp[i][j] = grid[i][j];
            else dp[i][j] = maxValue;
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
