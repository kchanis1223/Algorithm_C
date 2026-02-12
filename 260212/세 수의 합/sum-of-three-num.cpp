#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
long long k;
int arr[1000];

int main() {

    map<long long ,vector<int>> m;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]].push_back(i);
    }

    int result = 0;
    for(int i =0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            long long sum = arr[i] + arr[j];
            if(m[k - sum].empty()) continue;
            for(auto idx : m[k-sum]){
                if(idx != i && idx != j) {
                    //cout<<i<<","<<j<<","<<idx<<endl;
                    result += 1;
                }
            }
        }
    }
    cout<<result/3;
    // Please write your code here.

    return 0;
}
