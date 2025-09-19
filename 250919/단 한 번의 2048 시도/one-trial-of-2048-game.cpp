#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int grid[4][4];
char dir;

void ToLeft(){
    for(int i=0;i<4;i++){
        vector<int> v;
        for(int j=0;j<4;j++){
            if(grid[i][j] == 0) continue;
            if(v.empty()) { 
                v.push_back(grid[i][j]);
                continue;
            }
            if(v.back() == grid[i][j]){
                v.pop_back();
                v.push_back(grid[i][j] * 2 + 1);
            }
            else{
                v.push_back(grid[i][j]);
            }
        }
        while(v.size() < 4) v.push_back(0);
        for(int j =0;j<4;j++){
            grid[i][j] = (v[j] % 2 !=0? v[j] - 1: v[j]);
        }
    }
}
void ToDown(){
    for(int i=0;i<4;i++){
        vector<int> v;
        for(int j=0;j<4;j++){
            if(grid[3-j][i] == 0) continue;
            if(v.empty()) { 
                v.push_back(grid[3-j][i]);
                continue;
            }
            if(v.back() == grid[3-j][i]){
                v.pop_back();
                v.push_back(grid[3-j][i] * 2 + 1);
            }
            else{
                v.push_back(grid[3-j][i]);
            }
        }
        while(v.size() < 4) v.push_back(0);
        for(int j =0;j<4;j++){
            grid[3-j][i] = (v[j] % 2 !=0? v[j] - 1: v[j]);
        }
    }
}
void ToUp(){
    for(int i=0;i<4;i++){
        vector<int> v;
        for(int j=0;j<4;j++){
            if(grid[j][i] == 0) continue;
            if(v.empty()) { 
                v.push_back(grid[j][i]);
                continue;
            }
            if(v.back() == grid[j][i]){
                v.pop_back();
                v.push_back(grid[j][i] * 2 + 1);
            }
            else{
                v.push_back(grid[j][i]);
            }
        }
        while(v.size() < 4) v.push_back(0);
        for(int j =0;j<4;j++){
            grid[j][i] = (v[j] % 2 !=0? v[j] - 1: v[j]);
        }
    }
}
void ToRight(){
    for(int i=0;i<4;i++){
        vector<int> v;
        for(int j=0;j<4;j++){
            if(grid[i][3-j] == 0) continue;
            if(v.empty()) { 
                v.push_back(grid[i][3-j]);
                continue;
            }
            if(v.back() == grid[i][3-j]){
                v.pop_back();
                v.push_back(grid[i][3-j] * 2 + 1);
            }
            else{
                v.push_back(grid[i][3-j]);
            }
        }
        while(v.size() < 4) v.push_back(0);
        for(int j =0;j<4;j++){
            grid[i][3-j] = (v[j] % 2 !=0? v[j] - 1: v[j]);
        }
    }
}


int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;
    if(dir == 'L') ToLeft();
    if(dir == 'R') ToRight();
    if(dir == 'U') ToUp();
    if(dir == 'D') ToDown();

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    // Please write your code here.

    return 0;
}
