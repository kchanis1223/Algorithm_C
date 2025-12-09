#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int nums[12];

vector<vector<int>> all_moves;

void backtracking(vector<int> &v){
    if(v.size()== n){
        all_moves.push_back(v);
        return;
    }
    for(int select = 1;select<=k;select++){
        v.push_back(select);
        backtracking(v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m >> k;

    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> v= {};
    backtracking(v);

    // for(auto i : all_moves){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    for(auto moves : all_moves){
        int count =0;
        vector<int> k_positions(k+1,1);
        for(int i=0; i<moves.size();i++){
            k_positions[moves[i]] += nums[i];
        }
        for(auto kp : k_positions){
            if (kp >= m) count ++;
        }
        if(maxCount < count) maxCount = count;
    }
    cout<<maxCount;
    // Please write your code here.

    return 0;
}
