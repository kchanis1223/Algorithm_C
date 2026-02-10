#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int s[1000];
int b[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> b[i];
    }

    // Please write your code here.
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(10,vector<int>(12,0)));
    // dp[i][t][s] 는 i까지 고려했을때 야구팀 t명, 축구팀 s명 일때의 두팀의 능력 최대 값.

    
    for(int i=1; i<=n; i++){
        for(int t = 0 ; t<=9; t++){
            for(int k = 0; k<=11; k++){
                if(t > i || k > i || t+k > i) continue;
                vector<int> v;
                if(k>0) v.push_back(dp[i-1][t][k-1] + s[i-1]);
                if(t>0) v.push_back(dp[i-1][t-1][k] + b[i-1]);
                v.push_back(dp[i-1][t][k]);

                dp[i][t][k] = *max_element(v.begin(),v.end());
            }
        }
    }

    cout<<dp[n][9][11];
    return 0;
}
