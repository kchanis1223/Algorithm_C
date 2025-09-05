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

bool isValid(vector<int> v, int limit){
    
    int block = 1;
    int sum =v[0];
    for(int i=1;i<v.size() && block <=m ;i++){
        if(sum + v[i] > limit){
            block +=1;
            sum = v[i];
        }
        else{
            
            sum += v[i];
        }
    }
    //cout<<"limit :"<<limit<<" block:"<<block<<endl;
    if(block <= m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }

    for(int groupMax =1; groupMax<5000;groupMax ++){
        if(isValid(v, groupMax)) {
            cout<< groupMax;
            break;
        }
    }
    
    // for(auto i : v){
    //     for(auto j : i){
    //         cout<< j<<" ";
    //     }
    //     cout<<endl;
    // }
    // Please write your code here.

    return 0;
}