#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[200000];

int main() {
    cin >> n;
    vector<int> v;
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(),v.end());
    int minN = INT_MAX;
    for(int i=0;i<n;i++){
        int dif = v[n+i] - v[i];
        if(minN > dif){
            minN = dif;
        }
    }
    cout<<minN;

    // Please write your code here.

    return 0;
}