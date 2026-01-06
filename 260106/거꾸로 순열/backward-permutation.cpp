#include <iostream>
#include <vector>

using namespace std;

int n;

void backtracking(vector<int> &v , vector<bool> &visited){
    if(v.size() == n){
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);

            backtracking(v,visited);
            
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    vector<int> v = {};
    vector<bool> visited = vector<bool>(n+1,false);
    backtracking(v,visited);
    return 0;
}
