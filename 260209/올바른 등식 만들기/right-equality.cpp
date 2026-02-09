#include <iostream>
#include <vector>

using namespace std;

int N, M;
int nums[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<vector<long long>> dp = vector<vector<long long>>(N+1, vector<long long>(41,0));
    // dp[i][j] 는 i번째 까지 진행하였을때 현재 합이 j-20인 경우의 경우의 수

    dp[0][0] = 0;
    dp[1][nums[0]+20] += 1;
    dp[1][-nums[0]+20] += 1;
    for(int i=1 ; i< N; i++){
        for(int j=0 ; j<=40; j++){
            if(j - nums[i]  < 0 ) dp[i+1][j] = dp[i][j+nums[i]];
            else if (j + nums[i] > 40 ) dp[i+1][j] = dp[i][j-nums[i]];
            else dp[i+1][j] = dp[i][j-nums[i]] + dp[i][j+nums[i]];

        }
    }
    // for(auto i : dp){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<dp[N][M+20];
    // for(int i=25;i<=40;i++){
    //     for(auto j : dp[i]){
    //         cout<<j <<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<<dp[N][M+20];
    // Please write your code here.

    return 0;
}
