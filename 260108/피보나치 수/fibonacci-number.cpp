#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    cin >> N;

    // Please write your code here.
    vector<int> dp = vector<int>(N+1,0);
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3;i<=N;i++){
        dp[i] = dp[i-1] +dp[i-2];
    }
    cout<<dp[N];
    return 0;
}
