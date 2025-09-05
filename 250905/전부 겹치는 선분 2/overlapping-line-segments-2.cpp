#include <iostream>
#include<vector>
using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
        v.push_back({x1[i],x2[i]});
    }
    string result;
    for(int i=0;i<v.size();i++){
        for(int p = 1;p<=100;p++){
            bool flag = true;
            for(int j=0;j<v.size();j++){
                if(j == i) continue;
                if(v[j].first <= p && p <= v[j].second)continue;
                flag = false;
                break;
            }
            if(flag) {
                result = "Yes";
                break;
            }
            result = "No";
        }
        if(result == "Yes") break;
    }
    cout<<result;

    // Please write your code here.

    return 0;
}