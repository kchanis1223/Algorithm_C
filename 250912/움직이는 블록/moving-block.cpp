#include <iostream>

using namespace std;

int n;
int blocks[10000];

int main() {
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
        total +=blocks[i];
    }
    int avg = total / n;
    int count =0;
    for(int i=0;i<n;i++){
        if(blocks[i] > avg) count += blocks[i] - avg;
    }
    cout<<count;
    // Please write your code here.


    return 0;
}