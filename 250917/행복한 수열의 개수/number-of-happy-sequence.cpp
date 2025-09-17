#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int total = 0;
    for(int x=0;x<n;x++){
        bool isValid = false;
        int value = 0;
        int count = 0;
        for(int y=0;y<n;y++){
            if(value == 0){
                value = grid[x][y];
                count +=1;
                continue;
            }
            if(value == grid[x][y]){
                count +=1;
            }
            else{
                value = grid[x][y];
                count = 1;
            }
            if(count == m){
                isValid = true;
                break;
            }
        }
        if(isValid) total +=1;
    }
    for(int y=0;y<n;y++){
        bool isValid = false;
        int value = 0;
        int count = 0;
        for(int x=0;x<n;x++){
            if(value == 0){
                value = grid[x][y];
                count +=1;
                continue;
            }
            if(value == grid[x][y]){
                count +=1;
            }
            else{
                value = grid[x][y];
                count = 1;
            }
            if(count == m){
                isValid = true;
                break;
            }
        }
        if(isValid) total +=1;
    }
    cout<<total;
    // Please write your code here.

    return 0;
}
