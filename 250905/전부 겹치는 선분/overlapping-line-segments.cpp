#include <iostream>

using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    // Please write your code here.
    string result;
    for(int l = 1;l<=100;l++){
        int flag = true;
        for(int i=0;i<n;i++){
            if( x1[i] <= l && l <= x2[i] )continue;
            flag = false;
        }
        if(flag){
            result = "Yes";
            break;
        }
        result = "No";
    }
    cout<<result;
    return 0;
}