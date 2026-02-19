#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
string words[1000];

int main() {
    cin >> n;
    map<string,int> m;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        sort(words[i].begin(),words[i].end());
        m[words[i]]++;
    }
    int result = 0;
    for(auto i : m){
        if(result < i.second) result = i.second;
    }
    cout<<result;

    // Please write your code here.

    return 0;
}
