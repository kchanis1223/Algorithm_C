#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int s[200], e[200], v[200];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> v[i];
    }
    vector<vector<int>> dp = vector<vector<int>>(M+1,vector<int>(N,INT_MIN));
    // dp[i][j] 는  i번째 날까지 고려했을때, i번째날에 j번쨰 옷을 입었을 경우 지금까지의 최대값

    for(int i=0;i<N;i++){
        if(s[i] == 1) dp[1][i] = 0;
    }
    // Please write your code here.
    for(int day =2 ; day <= M; day++){
        for(int cIdx =0; cIdx < N; cIdx++){
            if(s[cIdx] > day || e[cIdx] < day) continue;
            vector<int> tmp;
            for(int i=0;i <N; i++){
                tmp.push_back(dp[day-1][i] + abs(v[cIdx] - v[i]));
            }
            dp[day][cIdx] = *max_element(tmp.begin(),tmp.end());
        }
    }
    // for(auto i : dp){
    //     for(auto j :i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    cout<< *max_element(dp[M].begin(),dp[M].end());
    return 0;
}
