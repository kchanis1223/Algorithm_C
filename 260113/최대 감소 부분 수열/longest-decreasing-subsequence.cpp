#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;

int N;
int M[MAX_N];

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
        for(int j=0;j<i;j++){
            if(M[j] > M[i]) maxCount = dp[j];
        }
        dp[i] = maxCount + 1;
    }
    sort(dp.begin(),dp.end());
    cout<<dp[N-1];
    return 0;
}
