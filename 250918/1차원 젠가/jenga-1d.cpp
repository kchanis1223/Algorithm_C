#include <iostream>
#include <vector>

using namespace std;

int n;
int blocks[100];
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
     vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
        v.insert(v.begin(),(blocks[i]));
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;
    vector<int> v2;
    for(int i=0;i<v.size();i++){
        if(v.size() - e1 <= i && i <= v.size() - s1) continue;
        v2.push_back(v[i]);
    }
    vector<int>v3;
    for(int i=0;i<v2.size();i++){
        if(v2.size() - e2 <= i && i <= v2.size() - s2) continue;
        v3.push_back(v2[i]);
    }
    
    // for(auto i : v2){
    //     cout<<i<<endl;
    // }
    // cout<<endl;
    cout<<v3.size()<<endl;
    for(int i=v3.size()-1;i>=0;i--){
        cout<<v3[i]<<endl;
    }
    return 0;
}
