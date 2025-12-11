#include <iostream>
#include <vector>
using namespace std;

int n, m;
int A[20];

int maxCal = 0;

void backtracking(int size, int result, int idx){
    if(size == m){
        if(result > maxCal) maxCal = result;
        return;
    }
    for(int i=idx;i<n;i++){
        backtracking(size+1,result^A[i],i+1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    backtracking(0,0,0);
    // Please write your code here.
    cout<<maxCal;
    
    return 0;
}