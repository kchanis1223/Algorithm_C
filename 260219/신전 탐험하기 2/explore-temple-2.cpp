#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int n;
int l[1001], m[1001], r[1001];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> m[i] >> r[i];
    }

    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(3,vector<int>(3,0)));
    //dp[i][j][k] means until i floor & choose j dir 0:left/ 1:mid / 2 :right & first floor dir
    // Please write your code here.
    dp[1][0][0] = l[0];
    dp[1][1][1] = m[0];
    dp[1][2][2] = r[0];
    for(int k = 0; k<=2 ; k++){
        for(int i = 2; i<=n; i++){
            dp[i][0][k] = max(dp[i-1][1][k], dp[i-1][2][k]) + l[i-1];
            dp[i][1][k] = max(dp[i-1][0][k], dp[i-1][2][k]) + m[i-1];
            dp[i][2][k] = max(dp[i-1][0][k], dp[i-1][1][k]) + r[i-1];
        }
    }
    vector<int> v = {dp[n][0][1],dp[n][0][2],dp[n][1][0],dp[n][1][2],dp[n][2][0],dp[n][2][1]};
    cout<<*max_element(v.begin(),v.end());

    return 0;
}
