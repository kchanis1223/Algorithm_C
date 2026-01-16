#include <iostream> 
#include <vector>
#include <climits>

using namespace std;

int n, m;
int e[100], t[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> t[i];
    }

    int dpSize = 1000000;
    vector<vector<int>> dp = vector<vector<int>>(n+1,vector<int>(dpSize+1,INT_MAX/2));
    // dp[i][k] i번째 퀘스트까지 고려했을때 경험치 k인 경우 총 시간이 최소인 값
    for(int i=0;i<=n;i++) dp[i][0] = 0;

    for(int i=1;i<=n; i++){
        int exp = e[i-1];
        int time = t[i-1];
        for(int k = 1; k <= dpSize ; k++){
            if(k - exp < 0){
                dp[i][k] = dp[i-1][k];
                continue;
            }
            if(dp[i-1][k] == INT_MAX/2 && dp[i-1][k-exp] == INT_MAX/2) continue;
            dp[i][k] = min(dp[i-1][k], dp[i-1][k-exp] + time);
            
        }
    }

    int result = INT_MAX;
    for(int i=0;i<=n; i++){
         for(int j=0; j<=dpSize;j++){
            //cout<<dp[i][j]<<" ";
            if(j >= m) result = min(result,dp[i][j]);
        }
        //cout<<endl;
    }
    //cout<<endl;
    cout<<result;

    return 0;
}
