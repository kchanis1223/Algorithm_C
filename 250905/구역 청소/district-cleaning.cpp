#include <iostream>

using namespace std;

int a, b, c, d;

int main() {
    cin >> a >> b;
    cin >> c >> d;

    // Please write your code here.
    int overlap;
    if(a <=c && c<= b){
        if(d<=b) overlap = d-c;
        else overlap = b-c;
    }
    else if(a <=d && d<= b){
        if(c<=a) overlap = d-a;
        else overlap = d-c;
    }
    cout<<b-a + d-c - overlap;
    return 0;
}