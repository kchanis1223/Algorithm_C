#include <iostream>
#include <set>
using namespace std;

int n, m;
int A[200000];
int B[200000];

int main() {
    cin >> n >> m;

    set<int> sA,result;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sA.insert(A[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> B[i];
        if(sA.find(B[i]) == sA.end()) result.insert(B[i]);
        else sA.erase(B[i]);
    }
    for(auto i : sA) result.insert(i);
    cout<<result.size();

    // Please write your code here.

    return 0;
}
