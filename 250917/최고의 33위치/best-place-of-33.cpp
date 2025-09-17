#include <iostream>
#include <vector>
using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int maxCount = 0;
    for(int x=0;x<N;x++){
        for(int y =0;y<N;y++){
            int count = 0;
            bool isValid = true;
            for(int i =0;i<3;i++){
                for(int j=0;j<3;j++){
                    if( x + i >= N || y + j >= N){
                        isValid = false;
                        break;
                    }
                    if(grid[x+i][y+j] == 1)count +=1;
                }
            }
            if(isValid && maxCount < count) maxCount = count;
        }
    }
    cout<<maxCount;
    // Please write your code here.

    return 0;
}
