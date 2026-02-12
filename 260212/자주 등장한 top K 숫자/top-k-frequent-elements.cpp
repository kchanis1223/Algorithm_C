#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k;
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]] += 1;
    }
    vector<int> v;
    for(int i=0; i< k; i++){
        int maxValue = 0;
        int maxCount = 0;
        for(auto p : m){
            if(maxCount <= p.second){
                maxValue = p.first;
                maxCount = p.second;
            }
        }
        v.push_back(maxValue);
        m[maxValue] = 0;
    }
    for(auto i : v) cout<<i<<" ";
    // Please write your code here.

    return 0;
}
