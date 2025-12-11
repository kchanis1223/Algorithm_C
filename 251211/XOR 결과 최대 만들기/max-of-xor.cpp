#include <iostream>
#include <vector>
using namespace std;

int n, m;
int A[20];

int maxCal = 0;

void backtracking(vector<int> &v, int idx){
    if(v.size() == m){
        int cal = v[0];
        for(int i=1;i<v.size();i++){
            cal ^= v[i];
        }
        if(cal > maxCal) maxCal = cal;
        return;
    }
    for(int i=idx;i<n;i++){
        v.push_back(A[i]);
        backtracking(v,idx+1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> v= {};
    backtracking(v,0);
    // Please write your code here.
    cout<<maxCal;
    
    return 0;
}