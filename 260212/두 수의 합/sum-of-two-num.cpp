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
        if(m[k-arr[i]].empty()) continue;
        for(auto idx : m[k-arr[i]]){
            if(idx != i) result += 1;
            //cout<<i<<","<<idx<<endl;
        }
    }
    cout<<result/2;

    // Please write your code here.

    return 0;
}
