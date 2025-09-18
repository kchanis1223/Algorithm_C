#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

bool isValid(int x ,int y, int r, int c){
    if(x + r >= n || y + c >= m) return false;
    for(int i=x;i<=x+r;i++){
        for(int j =y;j<=y+c;j++){
            if(grid[i][j] < 0) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int maxCount = -1;
    for(int x =0;x<n;x++){
        for(int y =0;y<m;y++){

            for(int r = 0;r <n;r++){
                for(int c =0;c<n;c++){
                    if(isValid(x,y,r,c) && (maxCount < (r+1)*(c+1) ))  maxCount = (r+1)*(c+1);
                }
            }
        }
    }
    cout<<maxCount;
    // Please write your code here.

    return 0;
}
