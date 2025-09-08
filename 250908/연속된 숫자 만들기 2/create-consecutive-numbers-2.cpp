#include <iostream>

using namespace std;

int pos[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> pos[i];

    // Please write your code here.
    if(abs(pos[0] - pos[1]) == 2 || abs(pos[1] - pos[2]) == 2) cout<<1;
    else if ( (pos[0]+ 1 == pos[1] && pos[1] + 1 == pos[2]) || (pos[0] - 1 == pos[1] && pos[1] - 1 == pos[2]) ) cout<<0;
    else cout<<2;
    return 0;
}