#include <iostream>

using namespace std;

int n;
int a[10], b[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for(int start=int(a[0]/2) ;start<=int(b[0]/2);start++){
        int cur = 2 * start;
        bool isValid = true;
        for(int i=0;i<n;i++){
            if(a[i] > cur || b[i] < cur) {
                isValid = false;
                break;
            }
            cur *= 2;
        }
        if(isValid){
            cout<<start;
            break;
        }
    }

    // Please write your code here.

    return 0;
}