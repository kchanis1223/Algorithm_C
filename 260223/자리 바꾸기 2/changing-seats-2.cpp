#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int N, K;
int a[100000], b[100000];

int main() {
    cin >> N >> K;
    map<int,set<int>> m;
    vector<int> v;
    for(int i=1;i<=N;i++){
        m[i].insert(i);
        v.push_back(i);
    }
    for (int i = 0; i < K; i++) {
        cin >> a[i] >> b[i];
        int p1 = v[a[i]-1];
        int p2 = v[b[i]-1];
        m[p1].insert(b[i]);
        m[p2].insert(a[i]);
        v[a[i]-1] = p2;
        v[b[i]-1] = p1;
    }
    for (int i = 0; i < K; i++) {
        int p1 = v[a[i]-1];
        int p2 = v[b[i]-1];
        m[p1].insert(b[i]);
        m[p2].insert(a[i]);
        v[a[i]-1] = p2;
        v[b[i]-1] = p1;
    }
    for (int i = 0; i < K; i++) {
        int p1 = v[a[i]-1];
        int p2 = v[b[i]-1];
        m[p1].insert(b[i]);
        m[p2].insert(a[i]);
        v[a[i]-1] = p2;
        v[b[i]-1] = p1;
    }
    for(auto i : m){
        // cout<<i.first<<": ";
        // for(auto j : i.second) cout<<j<<" ";
        cout<<i.second.size() <<endl;
    }
    // Please write your code here.

    return 0;
}
