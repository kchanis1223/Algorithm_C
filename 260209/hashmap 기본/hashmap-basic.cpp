#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];

int main() {
    cin >> n;

    unordered_map<int,int> um; 
    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        cin >> k[i];
        if (cmd[i] == "add") {
            cin >> v[i];
            um[k[i]] = v[i];
        }
        else if (cmd[i] == "remove"){
            um.erase(k[i]);
        }
        else{
            auto it = um.find(k[i]);
            if(it != um.end()) cout<< um[k[i]]<<endl;
            else cout<< "None"<<endl;
        }
    }

    // Please write your code here.

    return 0;
}
