#include <iostream>
#include <vector>

using namespace std;

int n;
int maxCount = 0;
int x1[15], x2[15];
vector<pair<int,int>> lines;

bool isValid(vector<pair<int,int>> v, pair<int,int> l){
    for(auto line : v){
        if(line.first <= l.first && l.first <= line.second) return false;
        if(l.first <= line.second && line.second <=l.second) return false;
    }
    return true;
}

void backtracking(int idx, vector<pair<int,int>> &v){
    if(idx == n) {
        if(v.size() > maxCount) maxCount = v.size();
        return;
    }

    for(int i=idx; i <n;i++){
        if(isValid(v,lines[i])){
            v.push_back(lines[i]);
            backtracking(i+1,v);
            v.pop_back();
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        lines.push_back({x1[i],x2[i]});
    }
    vector<pair<int,int>> v = {};
    backtracking(0,v);
    cout<<maxCount;
    // Please write your code here.

    return 0;
}
