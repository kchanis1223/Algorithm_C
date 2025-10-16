#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int r, c;
char directions[10000];

struct Dice{
    int u,f,s;

    Dice(int up, int front, int side){
        u = up; f = front; s = side;
    }
    void turnDice(int dir){
        if(dir == 0){ //상
            int new_u = f;
            int new_f = 7-u;
            int new_s = s;
            u = new_u; f = new_f; s = new_s;
        }
        else if (dir == 1){ // 하
            int new_u = 7 - f;
            int new_f = u;
            int new_s = s;
            u = new_u; f = new_f; s = new_s;
        }
        else if (dir == 2){ // 좌
            int new_u = s;
            int new_f = f;
            int new_s = 7-u;
            u = new_u; f = new_f; s = new_s;
        }
        else if (dir == 3){ // 우
            int new_u = 7-s;;
            int new_f = f;
            int new_s = u;
            u = new_u; f = new_f; s = new_s;
        }
    }
    int getBack(){
        return 7-u;
    }
};

vector<vector<int>> grid;

bool checkRange(int x , int y){
    return (x >= 0 && x < n && y >=0 && y <n)? true:false;
}

int main() {
    cin >> n >> m >> r >> c;
    
    grid = vector<vector<int>>(n,vector<int>(n,0));
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    int curX = r-1;
    int curY = c-1;
    Dice dice(1,2,3);
    grid[r-1][c-1] = dice.getBack();
    for (int i = 0; i < m; i++) {
        cin >> directions[i];

        int nxtX, nxtY;
        int dir = -1;
        if(directions[i] == 'U') dir = 0;
        else if(directions[i] == 'D') dir = 1;
        else if(directions[i] == 'L') dir = 2;
        else if(directions[i] == 'R') dir = 3;

        nxtX = curX + dx[dir]; nxtY = curY +dy[dir];
        if(!checkRange(nxtX,nxtY)) continue;
        curX = nxtX; curY = nxtY;
        dice.turnDice(dir);
        grid[nxtX][nxtY] = dice.getBack();

    }

    int sum = 0;
    for(auto i : grid){
        for(auto j : i){
            sum +=j;
        }
    }
    cout<<sum;

    // Please write your code here.

    return 0;
}
