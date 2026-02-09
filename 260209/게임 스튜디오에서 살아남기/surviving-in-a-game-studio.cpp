#include <iostream>
#include <vector>

using namespace std;

int n;
int mod = 1000000000 + 7;
int main() {
    cin >> n;

    // Please write your code here.
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(4, vector<vector<int>>(3,vector<int>(n+1,0)));
    // dp[t][b][i]는 T를 t번 마지막부터 연속 B를 b번 받으면서 i길이 일때의 가짓수.
    dp[0][0][1] = 1;
    dp[0][1][1] = 1;
    dp[1][0][1] = 1;
    for(int i = 2; i<=n; i++){
        for(int t =0; t<3 ; t ++){
            for(int b = 0 ; b<= 2; b++){
                dp[t][0][i] += dp[t][b][i-1]; // g추가 하는 경우
                dp[t][0][i] %= mod;
                if(t>0) {
                    dp[t][0][i] += dp[t-1][b][i-1]; // t추가 하는 경우
                    dp[t][0][i] %= mod;
                }
                
                if(b>0) {
                    dp[t][b][i] += dp[t][b-1][i-1]; // b추가하는 경우
                    dp[t][b][i] %= mod;
                }
                
            }
        }
    }
    
    int result = 0;
    for(int i=0;i<4; i++){
        for(int j=0;j<3;j++){
            result += dp[i][j][n];
        }
    }
    cout<<result;
    return 0;
}
