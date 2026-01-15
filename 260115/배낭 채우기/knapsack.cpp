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
    vector<vector<int>> dp = vector<vector<int>>(N,vector<int>(M+1,0)); 
    // dp[보석 종류i][무게w] = 최대 가치 , i 보석 종류까지 선택했을때 t 무게이상일때의 따른 최대 가치
    dp[0][w[0]] = v[0];
    
    for(int i =1;i<N;i++){
        int weight = w[i];
        int value = v[i];
        for(int k=0;k<=M;k++){
            if(k - weight >= 0) dp[i][k] = max(dp[i-1][k], dp[i-1][k-weight]+value);
            else dp[i][k] = dp[i-1][k];
        }
    }

    int result = 0;
    for(auto i : dp){
        for(auto j : i) {result = max(result,j);} //cout<<j<<" ";}
        //cout<<endl;
    }
    cout<<result;
    // Please write your code here.

    return 0;
}
