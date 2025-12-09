#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int nums[12];

int maxCount = 0;

int calCount(vector<int> v){
    int count = 0;
    vector<int> k_positions(k+1,1);
    for(int i=0;i<v.size();i++){
        k_positions[v[i]] += nums[i];
    }
    for(auto kp : k_positions){
        if(kp >= m) count ++;
    }
    return count;
}
void backtracking(vector<int> &v){
    if(calCount(v) > maxCount) maxCount = calCount(v);
    if(v.size()==n){
        return;
    }
    for(int select = 1;select<=4;select++){
        v.push_back(select);
        backtracking(v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> v = {};
    backtracking(v);
    cout<<maxCount;
    // Please write your code here.

    return 0;
}
