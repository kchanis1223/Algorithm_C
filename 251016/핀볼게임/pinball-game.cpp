#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

bool checkRange(int x , int y){
    return x>= 0 && x < n && y >=0 && y <n ? true : false;
}
// 오른쪽,왼쪽, 아래, 위 shoot dir = 0,1,2,3
int ColumnShoot(int col, bool isRight){
    int curX = col;
    int curY = isRight? 0:n-1;
    int dir = isRight? 0:1 ;
    int time = 1;
    while(true ){
        if(grid[curX][curY] != 0){
            if(grid[curX][curY] == 1){
                if(dir == 0) dir = 3;
                else if(dir == 1) dir = 2;
                else if(dir == 2) dir = 1;
                else if(dir == 3) dir = 0;
            }
            else if(grid[curX][curY] == 2){
                if(dir == 0) dir = 2;
                else if(dir == 1) dir = 3;
                else if(dir == 2) dir = 0;
                else if(dir == 3) dir = 1;
            }
        }
        time += 1;
        int nxtX = curX + dx[dir];
        int nxtY = curY + dy[dir];
        if(!checkRange(nxtX,nxtY)){
            break;
        }
        curX = nxtX; curY = nxtY;
    }
    return time;
}

int RowShoot(int row, int isDown){
    int curX = (isDown?0:n-1);
    int curY = row;
    int dir = isDown? 2:3;
    int time = 1;
    while(true){
        if(grid[curX][curY] != 0){
            if(grid[curX][curY] == 1){
                if(dir == 0) dir = 3;
                else if(dir == 1) dir = 2;
                else if(dir == 2) dir = 1;
                else if(dir == 3) dir = 0;
            }
            else if(grid[curX][curY] == 2){
                if(dir == 0) dir = 2;
                else if(dir == 1) dir = 3;
                else if(dir == 2) dir = 0;
                else if(dir == 3) dir = 1;
            }
        }
        time += 1;
        int nxtX = curX + dx[dir];
        int nxtY = curY + dy[dir];
        if(!checkRange(nxtX,nxtY)){
            break;
        }
        curX = nxtX; curY = nxtY;
    }
    return time;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    // Please write your code here.
    // 오른쪽,왼쪽, 아래, 위 shoot dir = 0,1,2,3
    int maxScore = 0;
    for(int i=0;i<n;i++){
        int score = max(ColumnShoot(i,true),ColumnShoot(i,false)); // i번째 행에서 오른쪽,왼쪽으로 쏘기
        maxScore = max(score,maxScore);
    }
    for(int i=0;i<n;i++){
        int score = max(RowShoot(i,true),RowShoot(i,false)); // i번째 열에서 아래,위로 쏘기
        maxScore = max(score,maxScore);
    }
    cout<<maxScore;
    return 0;
}
