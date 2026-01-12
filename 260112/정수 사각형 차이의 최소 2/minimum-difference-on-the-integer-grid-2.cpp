#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int grid[100][100];

bool checkRange(int x, int y){
    return x >=0 && x < n && y >=0 && y < n ? true:false;
}

bool inRange(int start, int end, int value){
    if(start <= value && value <= end) return true;
    else return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<int> result = vector<int>(101,INT_MAX);

    for(int lower = 1; lower<=100; lower++){
        bool isValid = false;
        int upper = lower;
        while(upper <= 100 ){
            if( !inRange(lower,upper,grid[0][0]) || !inRange(lower,upper,grid[n-1][n-1]) ) {
                upper ++;
                continue;
            }
            vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(n,false));
            queue<pair<int,int>> q;
            q.push({0,0});
            visited[0][0] = true;

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n-1 && y == n-1){
                    isValid = true;
                    break;
                }
                if(checkRange(x+1,y) && !visited[x+1][y] && inRange(lower,upper,grid[x+1][y])){
                    q.push({x+1,y});
                    visited[x+1][y] = true;
                }
                if(checkRange(x,y+1) && !visited[x][y+1] && inRange(lower,upper,grid[x][y+1])){
                    q.push({x,y+1});
                    visited[x][y+1] = true;
                }
            }
            if(isValid) {
                //cout<<"upper : "<<upper<<endl;
                break;
            }
            upper++;
        }

        if(isValid){
            result[lower] = upper - lower;
            //cout<<"lower : "<<lower<<" , upper :"<<upper<<endl;
            //cout<< upper - lower;
        }
    }
    sort(result.begin(), result.end());
    cout<<result[0];
    

    return 0;
}
