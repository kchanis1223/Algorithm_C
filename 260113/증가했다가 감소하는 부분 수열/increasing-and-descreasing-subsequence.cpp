#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int sequence[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int result = 0;
    // Please write your code here.
    for(int turnIdx =0; turnIdx <n; turnIdx++){
        vector<int> increase_dp = vector<int>(n,0);
        vector<int> decrease_dp = vector<int>(n,0);
        increase_dp[0] = 1;
        for(int i=1;i<=turnIdx;i++){
            int maxValue = 0;
            for(int j=0;j<i;j++){
                if(sequence[j] < sequence[i] && maxValue < increase_dp[j]) maxValue = increase_dp[j];
            }
            increase_dp[i] = maxValue + 1;
        }
        decrease_dp[n-1] = 1;
        for(int i=n-2; i >= turnIdx; i--){
            int maxValue = 0;
            for(int j=n-1; j > i; j-- ){
                if(sequence[j] < sequence[i] && maxValue < decrease_dp[j]) maxValue = decrease_dp[j];
            }
            decrease_dp[i] = maxValue + 1;
        }
        // cout<<"turnIdx :"<<turnIdx<<endl;
        // cout<<"increase : ";
        // for(auto i :increase_dp)cout<<i<<" ";
        // cout<<endl<<"decrease : ";
        // for(auto i : decrease_dp)cout<<i<<" ";
        // cout<<endl;
        int maxCount = 0;
        for(int i=0;i<n;i++){
            int cnt = increase_dp[i] + decrease_dp[i];
            if(maxCount < cnt) maxCount = cnt;
        }
        result = max(result,maxCount);
    }
    cout<<result-1;

    return 0;
}
