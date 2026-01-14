#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int A[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> dp = vector<int>(m+1,INT_MAX);
    dp[0] = 0;
    // for(int i=1;i<=m;i++){
    //     for(int j=0;j<n;j++){
    //         if( i - A[j] > 0 && dp[i-A[j]] != INT_MAX ) dp[i] = min(dp[i] , dp[i-A[j]] + 1);
    //     }
    // }
    for(int i=0;i<n;i++){
        int x = A[i];
        for(int s=m; s>=x; s--){
            if(dp[s-x] != INT_MAX) dp[s] = min(dp[s],dp[s-x] + 1);
        }
    }
    dp[m] != INT_MAX ? cout<< dp[m] : cout<<-1;
   

    return 0;
}
