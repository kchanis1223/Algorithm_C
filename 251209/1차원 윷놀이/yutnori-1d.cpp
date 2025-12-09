#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int nums[12];

int maxCount = 0;
vector<int> kp;

int calCount(vector<int> &kp){
    int count = 0;
    for(auto p : kp){
        if(p >= m) count ++;
    }
    return count;
}
void backtracking(vector<int> &v){
    
    int count = calCount(kp);
    if(count > maxCount) maxCount = count;
    if(v.size() == n){
        return;
    }
    for(int select = 1;select<=k;select++){
        if(kp[select] >= m) continue;
        v.push_back(select);
        kp[select] += nums[v.size()-1];
        backtracking(v);
        kp[select] -= nums[v.size()-1];
        v.pop_back();
        
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> v = {};
    kp = vector<int>(k+1,1);
    backtracking(v);
    cout<<maxCount;
    // Please write your code here.

    return 0;
}
