#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k;
string str;

int main() {
    cin >> n >> k;
    cin >> str;

    // Please write your code here.
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(k+1,vector<int>(2,INT_MIN)));
    // dp[i][t][p] i번쨰까지 k번 움직였을때, 현재위치 p인 상황에서의 최대 값
    dp[0][0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int t=0; t<=k; t++){
            if(t == 0) {
                dp[i][t][0] = dp[i-1][t][0] + (str[i-1] == 'L' ? 1 : 0 );
                dp[i][t][1] = dp[i-1][t][1] + (str[i-1] == 'R' ? 1 : 0 );
                continue;
            }
            dp[i][t][0] = max(dp[i-1][t][0] , dp[i-1][t-1][1]) + (str[i-1] == 'L' ? 1 : 0 );
            dp[i][t][1] = max(dp[i-1][t-1][0] , dp[i-1][t][1]) + (str[i-1] == 'R' ? 1 : 0 );
        }
    }
    int result =0;
    for(auto i : dp[n]){
        for(auto j : i) result = max(result, j);
    }
    cout<<result;
    return 0;
}
