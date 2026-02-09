#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int red[201];
int blue[201];

int main() {
    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        cin >> red[i] >> blue[i];
    }

    vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(2*n+1,0));
    // dp[i][j] 는 red인 카드를 i개 선택하여 현재 j 번째 선택까지 했을때의 최대 값

    dp[0][0] = 0;
    dp[1][1] = red[0];
    dp[0][1] = blue[0];

    for(int i =0; i<=n ; i ++){
        for(int j=1; j<=2*n; j++){
            if(i > 0) dp[i][j+1] = max(dp[i-1][j] + red[j] , dp[i][j] + blue[j]);
            else dp[i][j+1] = dp[i][j] + blue[j]; 
        }
    }

    // for(auto i : dp){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<<*max_element(dp[n].begin(), dp[n].end());
    // Please write your code here.

    return 0;
}
