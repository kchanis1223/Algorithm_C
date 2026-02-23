#include <iostream>
#include <set>
using namespace std;

int n;
int m;
int a[100000];
int b[100000];

int main() {
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if( s.find(b[i]) != s.end() ) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }

    // Please write your code here.

    return 0;
}
