#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, k;
int arr[100000];

map<int,vector<int>> m; // 값,인덱스
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]].push_back(i);
    }
    int result = 0;
    for(int i=0;i<n;i++){
        for(auto [value, v] : m){
            if(arr[i] + value != k) continue;
            if(!v.empty()) {
                for(auto idx : v){
                    if(idx != i) result += 1;
                    //cout<<i<<","<<idx<<endl;
                }
            }
        }
    }
    cout<<result/2;

    // Please write your code here.

    return 0;
}
