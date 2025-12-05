#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
int a[15], b[15];
int minCount;
vector<pair<int,int>> horizons;
vector<int> result;

vector<int> run(vector<pair<int,int>> v){
    vector<int> new_result;
    for(int i=0;i<n;i++){
        int value = i+1;
        int depth = 0;
        for(auto horizon : v){
            if(horizon.first < depth) continue;
            if(horizon.second == value){
                value += 1;
                depth = horizon.first;
                continue; 
            }
            if(horizon.second == value -1){
                value -=1;
                depth = horizon.first;
                continue;
            }
        }
        new_result.push_back(value);
    }
    return new_result;
}

bool isValid(vector<pair<int,int>> v){
    vector<int> new_result = run(v);
    // for(auto i : new_result){
    //     cout<< i<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<n;i++){
        if(new_result[i] != result[i]) return false;
    }
    return true;
}

void backtracking(int idx, vector<pair<int,int>> &v){
    if(isValid(v)){
        if(minCount > v.size()) minCount = v.size();
        return;
    }
    for(int i= idx;i<m;i++){
        v.push_back(horizons[i]);
        backtracking(i+1,v);
        v.pop_back();
    }
}
int main() {
    cin >> n >> m;
    minCount = m;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        horizons.push_back({b[i],a[i]});
    }
    sort(horizons.begin(),horizons.end());
    result = run(horizons);
    // for(auto i : result){
    //     cout<< i<<" ";
    // }
    // cout<<endl;

    vector<pair<int,int>> v= {};
    backtracking(0,v);
    cout<<minCount;
    // Please write your code here.

    return 0;
}
