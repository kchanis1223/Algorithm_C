#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string words[100000];

int main() {
    map<string,int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        m[words[i]] += 1;
    }

    // Please write your code here.
    int result = 0;
    for(auto i : m) result = max(result,i.second);
    cout<<result;
    return 0;
}
