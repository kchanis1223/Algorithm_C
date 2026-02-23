#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string words[100000];

int main() {
    cin >> n;
    map<string,int> m;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        m[words[i]] ++;
    }
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // Please write your code here.

    return 0;
}
