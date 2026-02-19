#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int l[1001], m[1001], r[1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> m[i] >> r[i];
    }
    
    // Please write your code here.
    vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(3,0));
    //dp[i][j] i층에서 j 0:left / 1:top/ 2:right 상태일때의 최대 보물
    for(int i = 1; i<= n; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + l[i-1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + m[i-1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + r[i-1];
    }
    cout<< *max_element(dp[n].begin(),dp[n].end());
    return 0;
}
