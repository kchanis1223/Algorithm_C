#include <iostream>

using namespace std;

int N;
int sequence[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    int idx =0;
    for(int i=N-1;i>0;i--){
        if(sequence[i] < sequence[i-1]){
            idx = i;
            //cout<<"i :"<<i<<endl;
            break;
        }
    }
    cout<<idx;
    // Please write your code here.

    return 0;
}