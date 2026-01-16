#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    int total = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
        total += arr[i];
    }
    vector<bool> dp = vector<bool>(total+1,false);
    dp[0] = true;

    for(auto x : v){
        for(int s=total; s>=x; s--){
            if(dp[s-x]) dp[s] = true;
        }
    }

    //for(auto i :dp) cout<<i<<" ";
    //cout<<endl;
    int minValue = INT_MAX;
    for(int i = 1 ; i<=total;i++){
        if(dp[i]) {
            minValue = min(minValue, abs(total - 2*i));
            //cout<<"i : "<<i<<endl;
        }
    }
    cout<<minValue;


    // vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(100000,INT_MAX)); 
    // //dp[i][t] 는 i번째까지 그룹을 나눴을때 A그룹이 t일때 "A-나머지"가 최소인 값
    // dp[0][v[0]] = abs(total - v[0] - v[0]);
    // for(int i=1;i<=n;i++){
    //     int value = v[i];
    //     for(int t=0; t<=100000; t++){
    //         if(t - value > 0 && dp[i][t-value] != INT_MAX) dp[i][t] = dp[t]
    //     }
    // }
     return 0;
}
