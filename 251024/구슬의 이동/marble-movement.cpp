#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m, t, k;
int r[2500], c[2500];
char d[2500];
int v[2500];

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};


bool checkRange(int x, int y){
    return x >=0 && x < n && y >=0 && y < n ? true: false;
}

struct Cube{
    int x,y;
    int dir;
    int speed;
    int value;
    Cube(int X , int Y , char Dir, int Speed, int Value){
        x = X; y = Y; speed = Speed; value = Value;
        if(Dir == 'U') dir = 0;
        if(Dir == 'D') dir = 1;
        if(Dir == 'L') dir = 2;
        if(Dir == 'R') dir = 3;
    }
    void move(){
        int t = 0;
        while(t < speed){
            if( ! checkRange(x + dx[dir], y + dy[dir])){
                if(dir == 0) dir = 1;
                else if (dir == 1) dir = 0;
                else if (dir == 2) dir = 3;
                else if (dir ==3) dir =2;
            }
            x += dx[dir] ; y += dy[dir];
            t ++;
        }
    }
};
map<int,Cube> cube_list;
vector<vector<vector<Cube>>> grid;

bool compare(Cube& a , Cube& b){
     if (a.speed != b.speed ) return a.speed > b.speed;
     return a.value > b.value;
}

int main() {
    cin >> n >> m >> t >> k;

    cube_list.clear();
    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i] >> d[i] >> v[i];
        r[i] --; c[i] --;
        Cube cube(r[i],c[i],d[i],v[i], i + 1);
        cube_list.insert(pair<int,Cube>(i+1,cube));
    }

    for(int time = 0 ; time< t; time++){
        for(auto &[num,cube] : cube_list){
            cube.move();
        }

        for(auto &[num,cube] : cube_list){
            //cout<<"cube "<<num<<" : "<<cube.x<<","<<cube.y<< " / "<<cube.dir<<" / "<<cube.speed<<endl;
        }

        grid = vector<vector<vector<Cube>>>(n,vector<vector<Cube>>(n));
        for(auto &[num,cube] : cube_list){
            int x = cube.x;
            int y = cube.y;
            grid[x][y].push_back(cube);
            sort(grid[x][y].begin(), grid[x][y].end(),compare);    
        }

        //cout<<grid[1][3][0].value<<" "<<grid[1][3][1].value<<" "<<grid[1][3][2].value<<endl;

        vector<int> remove_list;
        for(auto &[num,cube] : cube_list){
            
            if(grid[cube.x][cube.y].size() <= k) {
                continue;
            }

            while(grid[cube.x][cube.y].size() > k){
                Cube deleteCube = grid[cube.x][cube.y].back();
                grid[cube.x][cube.y].pop_back();
                remove_list.push_back(deleteCube.value);
            }
        }
        for(auto num :remove_list){
            auto it = cube_list.find(num);
            cube_list.erase(it);
        }
    }
    cout<<cube_list.size();
    // Please write your code here.

    return 0;
}
