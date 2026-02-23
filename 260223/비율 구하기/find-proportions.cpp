#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string words[10000];

int main() {
    cin >> n;
    map<string,int> m;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        m[words[i]] += 1;
    }
    double total = 0;
    for(auto s : m){
        total += s.second;
    }
    for(auto s : m){
        double ratio = double(s.second / total) * 100;
        
        cout<<fixed;
        cout.precision(4);
        cout<<s.first<<" "<<ratio<<endl;
    }

    // Please write your code here.

    return 0;
}
