#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int profit[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(n+1,0)); //
    for(int i=1;i<=n;i++){
        for(int l=1; l<=n;l++){
            if (l < i) {
                dp[i][l] = dp[i-1][l];
                continue;
            }
            vector<int> tmp = {dp[i-1][l] , dp[i-1][l-i]+ profit[i-1], dp[i][l-i] + profit[i-1]};
            dp[i][l] = *max_element( tmp.begin(),tmp.end());
        }
    }
    int result = 0;
    for(auto i : dp){
        for(auto j : i){
            //cout<<j<<" ";
            result = max(result,j);
        }
        //cout<<endl;
    }
    //cout<<endl;
    cout<<result;
    // Please write your code here.

    return 0;
}
