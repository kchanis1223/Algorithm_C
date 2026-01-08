#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N;
bool checkRange(int x){
    return x >= 0 && x <= 1000100 ? true: false;
}
int main() {
    cin >> N;

    // Please write your code here.
    queue<pair<int,int>> q; // value/d
    vector<bool> visited = vector<bool>(100000000,false);
    q.push({1,0});
    visited[1] = true;

    while(!q.empty()){
        
        int value = q.front().first;
        int d = q.front().second;
        q.pop();

        //cout<<"value : "<< value<<" / d : "<<d<<endl;
        if(value == N){
            cout<<d;
            break;
        }
        if(checkRange(value+1) && !visited[value+1])  {
            q.push({value+1,d+1});
            visited[value+1] = true;
        }
        if(checkRange(value-1) && !visited[value-1])  {
            q.push({value-1,d+1});
            visited[value-1] = true;
        }
        if(checkRange(2*value) && !visited[value*2])  {
            q.push({value*2,d+1});
            visited[value*2] = true;
        }
        if(checkRange(3*value) && !visited[value*3])  {
            q.push({value*3,d+1});
            visited[value*3] = true;
        }
    }
    return 0;
}
