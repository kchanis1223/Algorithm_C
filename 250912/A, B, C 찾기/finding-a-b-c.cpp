#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[7];

int main() {
    vector<int> v;
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    sort(v.begin(),v.end());
    int ABC = v[6];
    int A = v[0];
    int B = v[1];
    cout<<A<<" "<<B<<" "<<ABC-A-B;

    // Please write your code here.

    return 0;
}