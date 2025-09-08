#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[3];

int main() {
    vector<int> v;
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    // Please write your code here.
    sort(v.begin(), v.end());
    int count = 0;
    while( !(v[0] - v[1] == -1 && v[1] - v[2] == -1) ){
        //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        if(v[1] - v[0] > v[2] - v[1]){ // 145
            v[2] = v[1];
            v[1] = v[1]-1;
        }
        else{
            v[0] = v[1];
            v[1] = v[1]+1;
        }
        count +=1;
    }
    cout<<count;
    return 0;
}