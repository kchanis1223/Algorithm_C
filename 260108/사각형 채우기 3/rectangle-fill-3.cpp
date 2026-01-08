#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    vector<int> dp = vector<int>(n+1,0);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    
    for(int i=3;i<=n;i++){
        int exception = 0;
        for(int k=3; k<=i;k++){
            exception += dp[i-k];
            exception %= 1000000007;
        }
        dp[i] = dp[i-1] * 2 + dp[i-2] * 3 + 2*exception ;
        dp[i] %= 1000000007;
    }

    cout<< dp[n];
    return 0;
}
