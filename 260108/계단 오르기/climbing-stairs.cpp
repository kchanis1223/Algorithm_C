#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    vector<int> dp = vector<int>(n+1,0);
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    for(int i=5;i<=n;i++){
        dp[i] = dp[i-2] + dp[i-3];
    }
    cout<<dp[n];
    return 0;
}