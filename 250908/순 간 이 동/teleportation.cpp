#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a, b, x, y;

int main() {
    cin >> a >> b >> x >> y;

    // Please write your code here.
    int c1 = abs(a-b);
    int c2 = abs(a-x) + abs(b-y);
    int c3 = abs(a-y) + abs(b-x);

    vector<int> v = {c1,c2,c3};
    cout<<*min_element(v.begin(),v.end());
    return 0;
}