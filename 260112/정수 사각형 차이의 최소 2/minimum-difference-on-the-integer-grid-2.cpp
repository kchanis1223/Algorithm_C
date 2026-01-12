#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int grid[100][100];

struct Node{
    int min,max;
    Node(int min, int max) : min(min) , max(max) {}
};

bool checkRange(int x, int y){
    return x >=0 && x < n && y >=0 && y < n ? true:false;
}

vector<vector<Node>> dp; // dp[i][j] 까지 도달했을때 차이를 가장 작게한 최소,최대값

void changeDP(int x , int y, Node node){
    int value = grid[x][y];
    if (node.min <= value && value <= node.max){
        dp[x][y].min = node.min;
        dp[x][y].max = node.max;
    }
    else if(value < node.min){
        dp[x][y].min = value;
        dp[x][y].max = node.max;
        return;
    }
    else if(node.max < value){
        dp[x][y].max = value;
        dp[x][y].min = node.min;
        return;
    }
}
int calDif(Node node, int value){
    if(node.min <= value && value <= node.max) return node.max - node.min;
    else if(value < node.min) return node.max - value;
    else if(node.max < value) return value - node.min;
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp = vector<vector<Node>>(n,vector<Node>(n,Node(0,0)));

    dp[0][0].min = grid[0][0]; dp[0][0].max = grid[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j ==0) continue;
            else if(i == 0) changeDP(i,j,dp[i][j-1]);
            else if(j == 0) changeDP(i,j,dp[i-1][j]);
            else{
                //cout<<"i,j : "<<i<<","<<j<<endl;
                //cout<<"위쪽 : "<< calDif(dp[i-1][j],grid[i][j])<<"   왼쪽 : "<<calDif(dp[i][j-1],grid[i][j])<<endl;
                calDif(dp[i-1][j],grid[i][j]) < calDif(dp[i][j-1],grid[i][j]) ? changeDP(i,j,dp[i-1][j]) : changeDP(i,j,dp[i][j-1]);
            }
        }
    }
    
    // for(auto i : dp){
    //     for(auto j : i){
    //         cout<<"{"<<j.min<<","<<j.max<<"} ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    cout<<dp[n-1][n-1].max - dp[n-1][n-1].min;

    return 0;
}
