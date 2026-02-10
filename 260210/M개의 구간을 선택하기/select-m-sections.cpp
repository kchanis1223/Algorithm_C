#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int numbers[500];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    vector<vector<int>> dp = vector<vector<int>>(M+1,vector<int>(N+1,0));
    // dp[m][i] 는 i번째까지 m구간으로 나누었을때 최대 합.
    // Please write your code here.
    dp[1][1] = numbers[0];
    for(int i=2; i<= N; i++){
        for(int m = 1; m <= M; m++){
            if(m >= i) continue;
            vector<int> v = {dp[m][i-1] + numbers[i-1] , dp[m-1][i-2] + numbers[i-1] , dp[m][i-1]};
            dp[m][i] = *max_element(v.begin(),v.end());
        }
    }
    // for(auto i : dp){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<<dp[M][N];
    return 0;
}
