#include <iostream>

using namespace std;

int n;
int A[100];
int B[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int count = 0;
    for(int i=n-1;i>=1;i--){
        int dif = abs(B[i] - A[i]);
        count += dif;
        A[i-1] -= dif;
    }
    cout<<count;
    // Please write your code here.

    return 0;
}