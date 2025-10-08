#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int idx = 0;
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=k-1;j<=k-1+m-1;j++){
            if(grid[i][j] == 1){
                flag = false;
                break;
            }
        }
        if(i == n-1){
            idx = n-1;
            break;
        }
        if(!flag){
            idx = i-1;
            break;
        }
    }
    //cout<<"idx : "<<idx<<endl;
    if(idx >= 0){
        for(int j=k-1;j<=m-1+k-1;j++){
            grid[idx][j] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    // Please write your code here.

    return 0;
}
