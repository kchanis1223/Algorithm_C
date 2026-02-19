#include <iostream>
#include <vector>
using namespace std;

int n;
int mod = 1000000000 + 7;
int main() {
    cin >> n;

    // Please write your code here. 
    vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(10,0));
    //dp[i][j] 길이가 i인 끝자리가 j인 수의 갯수

    for(int i=1;i<=9;i++){
        dp[1][i] = 1;
    }
    for(int i = 2 ; i<= n; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][0] %= mod;
        dp[i][9] = dp[i-1][8];
        dp[i][9] %= mod;
        for(int j = 1; j<=8; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= mod;
        }
    }
    int result = 0;
    for(auto i : dp[n]){
        result += i;
        result %= mod;
    }
    cout<<result;
    return 0;
}
