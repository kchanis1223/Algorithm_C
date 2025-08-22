#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int N;
string str;

int main() {
    cin >> N;
    cin >> str;

    // Please write your code here.
    multiset<string> ms;
    for(int length = 1 ; length <=N;length++){
        for(int start=0;start<=N-length; start++){
            string tmp = "";
            for(int i=0;i<length;i++){
                tmp +=str[start+i];
            }
            ms.insert(tmp);
        }
    }
    int count = 0;
    for(auto &i :ms){
        if(ms.count(i) > 1){
            if(i.size() >=count) {
            
                count = i.size() +1;
            }
        }
    }
    // cout<<endl;
    // for(auto i :v){
    //     cout<<i<<" ";
    // }
    cout<<count;
    return 0;
}