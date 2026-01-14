#include <iostream>
#include <vector>

using namespace std;

int n, m;
int A[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<bool> dp = vector<bool>(m+1,false);
    // Please write your code here.
    dp[0] = true;
    
    for(int i=0;i<n;i++){
        int x = A[i];
        for(int s = m; s>= x ; s--){
            if(dp[s-x]) dp[s] = true;
        }
    }
    //for(auto i : dp) cout<<i<<" ";
    dp[m] ? cout<<"Yes" : cout<<"No";
    return 0;
}
