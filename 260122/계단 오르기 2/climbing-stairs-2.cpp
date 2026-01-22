#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int coin[1001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    vector<vector<int>> dp = vector<vector<int>>(4,vector<int>(n+1,0));
    // dp[t][i] = 1계단 오르기를 t번 하며 i번째 계단에 도달 했을때의 최대 동전 갯수
    dp[0][2] = coin[2];
    dp[1][1] = coin[1];
    for(int t =0 ; t <=3; t++){
        for(int i = 2; i <=n; i++){
            int prev_one = t -1 > 0 ? dp[t-1][i-1] : INT_MIN;
            dp[t][i] = max(dp[t][i-2] + coin[i] , prev_one + coin[i]);
        }
    }
    // for(auto i : dp){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    int result = 0;
    for(int i=0;i<=3;i++){
        result = max(result, dp[i][n]);
    }
    cout<<result;

    // Please write your code here.

    return 0;
}
