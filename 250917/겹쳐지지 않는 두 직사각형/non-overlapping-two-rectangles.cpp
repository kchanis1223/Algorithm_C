#include <iostream>

using namespace std;

int n, m;
int grid[5][5];
vector<vector<bool>> visited(n,vector<bool>(m,false));



int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> v;
    int maxSum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int sum =0;
            vector<int> tmp;
            for(int r =1;r<n;r++){
                for(int c =1;c<m;c++){
                    if(checkRange(i,j,r,c) ) {
                        int squareSum = calSquare(i,j,r,c);
                        if(squareSum > sum) {
                            sum = squareSum;
                            tmp = {i,j,r,c};
                        }
                    }
                }
            }
            if(maxSum < sum){
                v = tmp;
                maxSum = sum;
            }
        }
    }
    for(int i=v[0];i<v[0]+v[2];i++){
        for(int j=v[1];j<v[1]+v[3];j++){
            visited[i][j] = true;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int sum =0;
            vector<int> tmp;
            for(int r =1;r<n;r++){
                for(int c =1;c<m;c++){
                    if(checkRange(i,j,r,c) ) {
                        int squareSum = calSquare(i,j,r,c);
                        if(squareSum > sum) {
                            sum = squareSum;
                            tmp = {i,j,r,c};
                        }
                    }
                }
            }
            if(maxSum < sum){
                v = tmp;
                maxSum = sum;
            }
        }
    }

    // Please write your code here.

    return 0;
}
