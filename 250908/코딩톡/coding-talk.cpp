#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, p;
char c[100];
int u[100];

int main() {
    cin >> n >> m >> p;

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> u[i];
    }
    set<char> s;
    for(int i=0;i<n;i++){
        s.insert(alphabet[i]);
    }
    for(int i=p-1;i<n;i++){
        if(s.find(c[i]) != s.end()){
            s.erase(c[i]);
        }
    }
    vector<char> v;
    for(auto i : s){
        v.push_back(i);
    }
    if(u[p-1] ==0){
        cout<<" ";
        return 0;
    }
    sort(v.begin(),v.end());
    for(auto i : v){
        cout<<i<<" ";
    }

    // Please write your code here.

    return 0;
}