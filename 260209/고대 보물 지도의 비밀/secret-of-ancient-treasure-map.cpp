#include <iostream>
#include <vector>

using namespace std;

int n, k;
int numbers[100000];

int main() {
    cin >> n >> k;
    int maxValue = -100000;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        maxValue = max(numbers[i] , maxValue);
    }
    vector<vector<int>> dp = vector<vector<int>>(k+1,vector<int>(n+1, 0));
    // dp[i][j] 음수 i개 선택해서 numbers[j] 까지 고려했을때의 최대 값.
    if(numbers[0] < 0) dp[1][1] = numbers[0];
    else dp[0][1] = numbers[0];

    for(int i = 0; i<= k; i++){
        for(int j = 1; j< n ; j++){
            if(numbers[j] < 0 ){
                if(i > 0) dp[i][j+1] = max(dp[i-1][j] + numbers[j] , 0);
                else dp[i][j+1] = 0;

                
            } 
            else dp[i][j+1] = dp[i][j] + numbers[j];
        }
    }

    int result = -10000;
    for(auto i : dp){
        for(auto j : i){
            //cout<<j<<" ";
            result = max(j,result);
        }
        //cout<<endl;
    }
    //cout<<endl;
    if(maxValue < 0) cout<< maxValue;
    else cout<<result;


    // Please write your code here.

    return 0;
}
