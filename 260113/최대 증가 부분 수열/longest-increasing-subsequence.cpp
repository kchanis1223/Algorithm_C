#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    // Please write your code here.
    vector<int> dp = vector<int>(N,0);
    dp[0] = 1;
    for(int i=1;i<N;i++){
        int maxCount = 0;
        for(int j = 0; j<i;j++){
            if(M[i] > M[j] && maxCount < dp[j]) maxCount = dp[j];   
        }
        dp[i] = maxCount + 1;
    }
    //for(auto i : dp)cout<<i<<" ";
    int result = *max_element(dp.begin(),dp.end());
    cout<<result;
    
    return 0;
}
