#include <iostream>
#include<vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(),v.end());

    // Please write your code here.
    int minCost = INT_MAX;
    for(int target = v[0]; target <= v.back()-k; target ++){
        int cost = 0;
        for(int i=0;i<v.size(); i++){
            if(v[i] < target) cost += target - v[i];
            if(v[i] > target + k) cost += v[i] - target-k;
        }
        if(cost < minCost) {
            //cout<<"target : "<<target<<" cost : "<<cost<<endl;
            minCost = cost;
        }
    }
    cout<< minCost;
    return 0;
}