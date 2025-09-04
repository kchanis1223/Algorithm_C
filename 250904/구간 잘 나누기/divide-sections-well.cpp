#include <iostream>
#include <vector>
#include<climits>
#include<algorithm>
#include <numeric>
using namespace std;

int n, m;
int a[100];

void gen_combinations(int n , int k , vector<vector<int>> &v){
    if(k<0 || k >n) return;

    vector<int> cur(k);

    iota(cur.begin(),cur.end(),0);

    while(true){
        v.push_back(cur);
        int i = k-1;
        while(i>= 0 && cur[i] == i+n-k) i -=1;
        if(i<0)break;
        cur[i] +=1;
        for(int j=i+1;j<k;j++){
            cur[j] = cur[j-1] + 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> v;
    gen_combinations(n,m-1,v);

    // for(auto i : v){
    //     for(auto j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

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