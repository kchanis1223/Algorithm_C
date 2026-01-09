#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];

vector<int> dx = {0,1};
vector<int> dy = {1,0};

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
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j =0; j<n;j++){
            dp[i][j] = grid[i][j] + max( (checkRange(i-1,j)? dp[i-1][j] : 0) , (checkRange(i,j-1)? dp[i][j-1] : 0) );
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
