#include <iostream>
#include <climits>
#include<algorithm>
#include <queue>
using namespace std;

int X;

int main() {
    cin >> X;

    // Please write your code here.
    int minTime;
    vector<int> dv = {-1,0,1};
    vector<vector<int>> dp(10001,vector<int>(1000,INT_MAX)); // dp[위치][속도] = 시간
    dp[1][2] = 1;
    dp[1][1] = 1;
    queue<pair<int,int>> q;
    q.push({1,2});
    q.push({1,1});

    while(!q.empty()){
        auto [p,v] = q.front(); q.pop();
        
        for(int i=0;i<3;i++){
            int new_v = v + dv[i];
            if(new_v < 1) continue;
            int new_p = p + v;
            if(new_p > X) continue;

            if(dp[new_p][new_v] > dp[p][v] + 1){
                dp[new_p][new_v] = dp[p][v]+1;
                q.push({new_p,new_v});
            }

        }
    }
    // for(auto i : dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << dp[X][1]+1;
    return 0;
}