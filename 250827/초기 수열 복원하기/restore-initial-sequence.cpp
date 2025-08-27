#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int adjacent[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> adjacent[i];
    }

    // Please write your code here.
    for(int i=1;i<=adjacent[0] -1 ;i++){
        if(i == adjacent[0] - i) continue;
        vector<int>v;
        v.push_back(i); v.push_back(adjacent[0] - i);
        //cout<<"start: "<< v[0]<<" "<<v[1]<<endl;
        for(int j=1;j<n;j++){
            int nxt = adjacent[j] - v[j];
            if(nxt <=0) {
                //isValid = false;
                break;
            }
            if(find(v.begin(),v.end(),nxt) != v.end()) {
                //isValid = false;
                break;
            }
            v.push_back(adjacent[j] - v[j]);
        }
        // cout<<"end : ";
        // for(auto i :v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        if(v.size() == n){
            for(auto i : v){
                cout<<i<<" ";
            }
            break;
        }
    }
    return 0;
}