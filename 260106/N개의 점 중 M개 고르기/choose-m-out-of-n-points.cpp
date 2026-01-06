#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m;
int x[20], y[20];
int result = INT_MAX;


int calMinDistance(vector<int> v){
    int maxD = 0;
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            int xd = x[v[i]] - x[v[j]];
            int yd = y[v[i]] - y[v[j]];
            int value = xd*xd + yd*yd;
            if(value > maxD) maxD = value;
        }
    }
    return maxD;
}
void backtracking(vector<int> &v , int idx){
    if(v.size() == m){
        int minDistance = calMinDistance(v);
        // for(auto i : v) cout<<i<<" ";
        // cout<<endl;
        // cout<<"minDistance : " << minDistance<<endl;
        if(minDistance < result) result = minDistance;
        return;
    }

    for(int i= idx; i<n;i++){
        v.push_back(i);
        backtracking(v,i+1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }


    // Please write your code here.
    vector<int> v = {};
    backtracking(v,0);
    cout<<result;
    return 0;
}
