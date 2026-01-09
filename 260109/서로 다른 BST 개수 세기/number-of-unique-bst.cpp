#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.

    vector<int> dp = vector<int>(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for(int i=4;i<=n;i++){
        int sum = 0;
        for(int l = 0; l<= i; l++){
            sum += dp[l] * dp[i-1-l];
        }
        dp[i] = sum;
    }
    cout<<dp[n];
    return 0;
}
