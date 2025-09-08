#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pos[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> pos[i];

    // Please write your code here.
    vector<int> v = {pos[0],pos[1],pos[2]};
    sort(v.begin(),v.end());
    if(abs(v[0] - v[1]) == 2 || abs(v[1] - v[2]) == 2) cout<<1;
    else if ( (v[0]+ 1 == v[1] && v[1] + 1 == v[2]) || (v[0] - 1 == v[1] && v[1] - 1 == v[2]) ) cout<<0;
    else cout<<2;
    return 0;
}