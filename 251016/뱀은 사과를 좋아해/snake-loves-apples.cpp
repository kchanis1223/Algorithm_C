#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, K;
int x[10000], y[10000];
char d[1000];
int p[1000];

bool checkRange(int x , int y){
    return x>=0 && x < N && y >= 0 && y < N ? true :false;
}

struct Snake{
    vector<pair<int,int>> v;
    int headIdx;
    Snake(int x, int y){
        v.push_back({x,y});
        headIdx = 0;
    }
    void addHead(int x, int y){
        v.push_back({x,y});
        headIdx = v.size()-1;
    }
    void move(int x, int y){
        addHead(x,y);
        v.erase(v.begin());
    }
    bool checkBody(int x, int y){
        for(auto i : v){
            if(i.first == x && i .second == y) return false;
        }
        return true;
    }
};
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

map<pair<int,int>,bool> isApple;
int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
        isApple[{x[i]-1,y[i]-1}] = true;
    }

    int time = 0;

    int curX = 0;
    int curY = 0;
    Snake snake(curX,curY);
    
    bool isMoved = true;
    for (int i = 0; i < K; i++) {
        if(!isMoved) {
            time +=1;
            break;
        }
        cin >> d[i] >> p[i];
        int dir = -1;
        if(d[i] == 'U') dir = 0;
        else if(d[i] == 'D') dir = 1;
        else if(d[i] == 'L') dir = 2;
        else if(d[i] == 'R') dir = 3;

        int count = 0;
        while(count < p[i] ){
            if(checkRange(curX+dx[dir],curY+dy[dir])){
                curX += dx[dir]; curY +=dy[dir];
                if(!snake.checkBody(curX,curY)){
                    isMoved = false;
                    break;
                }

                if(isApple[{curX,curY}]){
                    snake.addHead(curX,curY);
                }
                else{
                    snake.move(curX,curY);
                }
            }
            else{
                isMoved = false;
                break;
            }
            count++;
        }
        // cout<<"snake : ";
        // for(auto i : snake.v){
        //     cout<<i.first<<","<<i.second<<" | ";
        // }
        // cout<<"ismoved :"<<isMoved<<endl;
        time += count;
    }
    cout<<time;

    // Please write your code here.

    return 0;
}
