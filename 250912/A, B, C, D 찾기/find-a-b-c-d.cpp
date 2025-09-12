#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[15];

int main() {
    vector<int> v;
    for (int i = 0; i < 15; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(),v.end());
    int A = v[0];
    int B = v[1];
    int C = v[2];
    int ABCD = v[14];

    // Please write your code here.
    cout<<A<<" "<<B<<" "<<C<<" "<<ABCD-A-B-C;
    return 0;
}