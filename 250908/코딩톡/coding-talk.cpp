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
    int cur_read = 0;
    set<char> cur_s;
    for(int i=0;i<p;i++){
        //cout<<i<<" :"<<endl;
        if(u[i] == cur_read) continue;
        cur_s = s;
        for(int j=i;j<m;j++){
            if(cur_s.find(c[j]) != cur_s.end()){
                cur_s.erase(c[j]);
            }
        }
        cur_read = u[i];
        // for(auto k : cur_s){
        //     cout<<k<<" ";
        // }
        // cout<<endl;
    }
    vector<char> v;
    for(auto i : cur_s){
        v.push_back(i);
    }
    sort(v.begin(),v.end());
    for(auto i : v){
        cout<<i<<" ";
    }

    // Please write your code here.

    return 0;
}