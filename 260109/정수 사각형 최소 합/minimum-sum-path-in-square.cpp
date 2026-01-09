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

    vector<vector<int>> dp = vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j =n-1; j>=0;j--){
            if(i == 0 && j == n-1) {dp[i][j] = grid[i][j]; continue;}
            
            dp[i][j] = grid[i][j] + min( (checkRange(i-1,j)? dp[i-1][j] : INT_MAX) , (checkRange(i,j+1)? dp[i][j+1] : INT_MAX) );
        }
    }
    cout<<dp[n-1][0];
    // Please write your code here.

    return 0;
}
