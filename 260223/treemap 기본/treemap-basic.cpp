#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];

int main() {
    cin >> n;

    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "add") {
            cin >> k[i] >> v[i];
            m[k[i]] = v[i];
        } 
        else if (cmd[i] == "remove" || cmd[i] == "find") {
            cin >> k[i];
            if(cmd[i] == "remove") m.erase(k[i]);
            if(cmd[i] == "find"){
                auto it = m.find(k[i]);
                if(it != m.end()){
                    cout<<it->second<<endl;
                }
                else{
                    cout<<"None"<<endl;
                }
            }
        
        }
        else{
            if(m.empty()) cout<< "None"<<endl;
            else{
                for(auto i : m){
                    cout<<i.second<<" ";
                }
                cout<<endl;   
            }
        }
    }

    // Please write your code here.

    return 0;
}
