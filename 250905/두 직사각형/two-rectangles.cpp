#include <iostream>

using namespace std;

int x1, y1, x2, y2;
int a1, b1, a2, b2;

bool isOverlap(){
    if(x1 < a1)
    {
        if(x2 < a1) return false;
        if(y2 < b1) return false;
        else if(y1 > b2) return false;
    }
    else{
        if(x1 > a2) return false;
        if(y2 < b1) return false;
        else if(y1 > b2) return false;
    }
    return true;
}
int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    // Please write your code here.
    isOverlap() ? cout<< "overlapping" : cout<< "nonoverlapping";
    return 0;
}