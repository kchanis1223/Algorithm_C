#include <iostream>
#include <string>
#include <map>

using namespace std;

string str;

int main() {
    cin >> str;
    map<char,int> m;
    for(auto i : str){
        m[i] += 1;
    }
    bool flag = false;
    for(auto i : str){
        if(m[i] < 2) {
            cout<<i;
            flag = true;
            break;
        }
    }
    if(!flag) cout<< "None";
    // Please write your code here.

    return 0;
}
