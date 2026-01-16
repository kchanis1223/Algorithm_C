#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    // Please write your code here.
    vector<vector<bool>> dp = vector<vector<bool>>(n+1,vector<bool>(total+1,false));
    // dp[i][k] = i까지 고려했을때 true A의 총합이 k가 가능한지
    for(int i=0;i<n+1;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        int value = arr[i-1];
        for(int s = 1; s <=total; s++){
            if(s-value < 0 ) continue;
            if( dp[i-1][s-value] || dp[i-1][s] ) dp[i][s] = true;
        }
    }
    // for(auto i : dp) {
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    if(total % 2 != 0) cout<<"No";
    else dp[n][total/2] ? cout<<"Yes" : cout<<"No";
    return 0;
}
