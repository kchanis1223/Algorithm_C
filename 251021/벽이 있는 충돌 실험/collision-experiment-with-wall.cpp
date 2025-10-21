#include <iostream>
#include <vector>

using namespace std;

int T;
int N, M;
int x[2500];
int y[2500];
char d[2500];

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

bool checkRange(int x, int y){
    return x >= 0 && x < N && y >=0 && y < N ? true : false;
}

struct Cube{
    int x, y, dir; // 상하좌우
    
    Cube(int X, int Y, int Dir){
        x = X; y = Y; dir = Dir;
    }
    void moveCube(){
        int nxtX = x + dx[dir];
        int nxtY = y + dy[dir];
        if(checkRange(nxtX,nxtY)){
            x = nxtX;
            y = nxtY;
        }
        else{
            if(dir == 0) dir = 1;
            else if(dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else if (dir == 3) dir = 2;
        }
    }
};

int main() {
    cin >> T;
    vector<int> result;
    vector<Cube> v;
    vector<vector<int>> grid;
    for (int t = 0; t < T; t++) {
        v.clear();
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> x[i] >> y[i] >> d[i];
            int dir = -1;
            if(d[i] == 'U') dir = 0;
            else if(d[i] == 'D') dir = 1;
            else if(d[i] == 'L') dir = 2;
            else if(d[i] == 'R') dir = 3;

            Cube cube(x[i]-1,y[i]-1,dir);
            v.push_back(cube);
        }

        for(int r = 0 ; r < N*N; r++){
            grid = vector<vector<int>>(N,vector<int>(N,0));
            for(auto &cube : v){
                cube.moveCube();
                grid[cube.x][cube.y] += 1;
            }
            vector<Cube> tmp;
            for(auto &cube : v){
                if(grid[cube.x][cube.y] == 1) tmp .push_back(cube);
            }
            v = tmp;
            // cout<<" v:"<<endl;
            // for(auto cube :v){
            //     cout<<cube.x<<","<<cube.y<<" dir : "<<cube.dir<<endl;
            // }
        }
        result.push_back(v.size());
    }
    for(auto i : result){
        cout<<i<<endl;
    }
    

    
    // Please write your code here.

    return 0;
}
