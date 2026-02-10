#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
string words[100000];
string queries[100000];

map<string,string> sm;
map<string,string> nm;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        sm[words[i]] = to_string(i);
        nm[to_string(i)] = words[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
        if( sm.find(queries[i]) != sm.end() ) cout<< sm[queries[i]]<<endl;
        else cout<< nm[queries[i]]<<endl; 
    }

    // Please write your code here.

    return 0;
}
