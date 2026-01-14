#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int coin[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    vector<int> dp = vector<int>(M+1,INT_MAX);
    for(int i = 0;i<N;i++){
        dp[coin[i]] = 1;
    }

    for(int i=1;i<=M;i++){
        for(int j=0;j<N;j++){
            if(i - coin[j] > 0 && dp[i-coin[j]] != INT_MAX) dp[i] = min(dp[i] , dp[i-coin[j]] + 1);
        }
    }
    if(dp[M] != INT_MAX) cout<<dp[M];
    else cout<<-1;
    //for(auto i : dp) cout<<i<<" ";
    // Please write your code here.

    return 0;
}
