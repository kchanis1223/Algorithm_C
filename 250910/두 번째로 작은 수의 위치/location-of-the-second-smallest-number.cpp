#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[100];

int main() {
    cin >> n;
    vector<int> v;
    vector<int> sorted_v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
        sorted_v.push_back(a[i]);
    }
    sort(sorted_v.begin(),sorted_v.end());

    int min = sorted_v[0];
    int secondMin = 101;
    bool flag = false;
    for(int i=1;i<n;i++){
        if(sorted_v[i] == min) continue;
        if(sorted_v[i] == secondMin){
            flag = false;
            break;
        }
        if(secondMin > sorted_v[i] ){
            secondMin = sorted_v[i];
            flag = true;
        }
    }
    // Please write your code here.
    if(!flag)cout<<-1;
    else{ 
        int idx = 0;
        for(int i=0;i<n;i++){
            if(v[i] == secondMin){
                idx = i;
                break;
            }
        }
        cout<<idx+1;
    }
    return 0;
}