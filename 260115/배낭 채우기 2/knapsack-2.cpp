#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int w[100], v[100];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp = vector<vector<int>>(N+1,vector<int>(M+1,0));

    for(int i=1;i<=N;i++){
        int weight = w[i-1];
        int value = v[i-1];
        for(int k=1;k<=M;k++){
            if(k-weight < 0){
                dp[i][k] = dp[i-1][k];
                continue;
            }
            vector<int> tmp = { dp[i-1][k], dp[i-1][k-weight] + value, dp[i][k-weight] + value };
            dp[i][k] = *max_element(tmp.begin(),tmp.end());
        }
    }
    int result = 0;
    for(auto i : dp){
        for(auto j : i){
            result = max(result,j);
           // cout<<j<<" ";
        }
        //cout<<endl;
    }
    //cout<<endl;
    cout<<result;
    return 0;
}
