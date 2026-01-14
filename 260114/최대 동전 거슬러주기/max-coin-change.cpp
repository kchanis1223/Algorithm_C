#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int coin[100];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    vector<int> dp = vector<int>(M+1,0);
    for(int i=0;i<N;i++){
        dp[coin[i]] = 1;
    }
    dp[0] = 0;
    for(int i = 1;i<=M;i++){
        for(int j=0;j<N;j++){
            if(i-coin[j] > 0 && dp[i - coin[j]] != 0) dp[i] = max(dp[i], dp[ i - coin[j]] + 1);
        }
    }
    //for(auto i : dp) cout<<i<<" ";
    //cout<<endl;
    cout<<dp[M];
    // Please write your code here.

    return 0;
}
