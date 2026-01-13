#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x1[1000];
int x2[1000];

int main() {
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        v.push_back({x1[i],x2[i]});
    }

    // Please write your code here.
    sort(v.begin(),v.end());
    vector<int> dp = vector<int>(n,1); // i번째 선분을 마지막으로 선택했을때의 최대 선택 가능 선분의 갯수

    for(int i=1;i<n;i++){
        for(int j=0; j<i;j++){
            if(v[j].second < v[i].first) dp[i] = max(dp[i],dp[j] + 1);
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}
