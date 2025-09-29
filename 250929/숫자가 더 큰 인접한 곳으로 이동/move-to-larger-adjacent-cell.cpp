#include <iostream>
#include <vector>

using namespace std;

int n;
int r, c;
int a[100][100];

bool checkRange(int x, int y){
    if(x >= 0 && x < n && y >=0 && y <n) return true;
    return false;
}
int main() {
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    int curX = r;
    int curY = c;
    bool isMoved  = true;
    
    vector<int> result= {a[curX][curY]};
    
    while(true){
        int dir = -1;
        for(int i=0;i<4;i++){
            if( a[curX][curY] < a[curX + dx[i]][curY + dy[i]]){
                dir = i;
                break;
            }
        }
        if(dir == -1) break;
        curX += dx[dir]; curY +=dy[dir];
        result.push_back(a[curX][curY]);
    }

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    // Please write your code here.

    return 0;
}
