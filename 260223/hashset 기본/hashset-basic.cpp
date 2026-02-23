#include <iostream>
#include <map>

using namespace std;

int n;
string command[100000];
int x[100000];

int main() {
    cin >> n;
    map<int,bool> m;
    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];
        if(command[i] == "add"){
            m[x[i]] = true;
        }
        if(command[i] == "remove"){
            m.erase(x[i]);
        }
        if(command[i] == "find"){
            auto it = m.find(x[i]);
            if(it != m.end()) cout<<"true"<<endl;
            else cout<<"false"<<endl;
        }
    }

    // Please write your code here.

    return 0;
}
