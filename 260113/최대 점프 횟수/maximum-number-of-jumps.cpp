#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int arr[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    vector<int> dp = vector<int>(n,0); // i 까지 최대 점프 횟수로 도달했을때의 점프 횟수
    dp[0] = 0;
    for(int i=1;i<n;i++){
        int maxCount = -1;
        for(int j=0;j<i;j++){
            if(i - j <= arr[j] && maxCount < dp[j]) maxCount = dp[j];
        }
        if(maxCount != -1) dp[i] = maxCount + 1;
    }

    vector<bool> visited = vector<bool>(n,false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=1;i<=arr[x];i++){
            int nx = x + i;
            if(nx < n && !visited[nx]) {
                q.push(nx);
                visited[nx] = true;
            }
        }
    }
    int idx = 0;
    while(visited[idx]){
        idx++;
    }
    //for(auto i : dp) cout<<i<<" ";
    //cout<<endl;
    cout<<*max_element(dp.begin(),dp.begin()+idx);
    return 0;
}
