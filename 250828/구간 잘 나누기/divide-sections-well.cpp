#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
using namespace std;

int n, m;
int a[100];
vector<vector<int>> v;
void dfs(int idx, vector<int> l){
    l.push_back(idx);
    if(l.size() == m-1){
        v.push_back(l);
        return;
    }
    for(int i=idx+1;i<n;i++){
        dfs(i,l);
    }
    return;
}

int main() {
    cin >> n >> m;
    v = vector<vector<int>>();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        dfs(i,{});
    }

    int result = INT_MAX;
     for(auto &walls : v){
        vector<int> group;
        for(int i=0;i<=walls.size();i++){
            int start = (i==0? 0 : walls[i-1]);
            int end = (i == walls.size() ? n:walls[i]);
            int sum = 0;
            for(int j = start;j<end;j++){
                sum += a[j];
            }
            group.push_back(sum);
        }
        // for(auto i : walls){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(auto i : group){
        //     cout<<i<<" ";
        // }
        // cout<<endl<<endl;
        int maxSum = *max_element(group.begin(),group.end());
        if(result > maxSum) result = maxSum;
    }
    cout<<result;
    // for(auto i : v){
    //     for(auto j : i){
    //         cout<< j<<" ";
    //     }
    //     cout<<endl;
    // }
    // Please write your code here.

    return 0;
}