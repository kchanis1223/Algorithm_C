#include <iostream>
#include <algorithm>
using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    // Please write your code here.

    pair<int,int> p1 = {min(x1,a1) , min(y1,b1)};
    pair<int,int> p2 = {max(x2,a2) , max(y2,b2)};

    int d = max(p2.first - p1.first , p2.second - p1.second);
    cout<<d*d;
    return 0;
}