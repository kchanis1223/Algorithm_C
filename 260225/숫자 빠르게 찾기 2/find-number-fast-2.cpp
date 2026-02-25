#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
int arr[100000];
int queries[100000];

int main() {
    cin >> n >> m;

    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
        auto it = s.upper_bound(queries[i]-1);
        if(it != s.end()) cout<< *it<<endl;
        else cout<< -1<<endl;
    }

    // Please write your code here.

    return 0;
}
