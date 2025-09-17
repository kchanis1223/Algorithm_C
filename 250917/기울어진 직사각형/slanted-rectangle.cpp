#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[20][20];

bool checkValid(int x, int y, int i, int j){
    if(x - i >= n) return false;
    if( y + i >= n) return false;

    if(x - i - j < 0) return false;
    if( y + i - j < 0) return false;

    if( y - j < 0) return false;

    return true;
}

int calSum(int x , int y , int i, int j){
    int sum = 0;
    int curX = x;
    int curY = y;
    for(int k=1;k<=i;k++){
        curX -=1;
        curY +=1;
        sum +=grid[curX][curY];
    }
    for(int k=1;k<=j;k++){
        curX -=1;
        curY -=1;
        sum +=grid[curX][curY];
    }
    for(int k=1;k<=i;k++){
        curX +=1;
        curY -=1;
        sum +=grid[curX][curY];
    }
    for(int k=1;k<=i;k++){
        curX +=1;
        curY +=1;
        sum +=grid[curX][curY];
    }
    return sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int result = 0;
    for(int x =0;x<n;x++){
        for(int y =0;y<n;y++){
            int maxSum = 0;
            for(int i=1;i<n;i++){
                for(int j=1;j<n;j++){
                    if(checkValid(x,y,i,j)){
                        int sum = calSum(x,y,i,j);
                        if(maxSum < sum) maxSum = sum;
                    }
                }
            }
            if(result < maxSum) result = maxSum;
        }
    }
    cout<<result;
    // Please write your code here.

    return 0;
}
