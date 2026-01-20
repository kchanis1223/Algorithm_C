#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    vector<int> dp = vector<int>(n,0);
    dp[0] = arr[0];
    for(int i =1; i <n; i ++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }
    //for(auto i : dp) cout<<i<<" ";
    //cout<<endl;
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}
