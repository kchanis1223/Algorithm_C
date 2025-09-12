#include <iostream>
#include<climits>
using namespace std;

int n;
int x1[100], x2[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    // Please write your code here.
    int minN = INT_MAX;
    for(int i=0;i<n;i++){
        int start=100;
        int end = 1;
        for(int j=0; j<n ;j++){
            if(j == i)continue;
            if(start > x1[j]) start = x1[j];
            if(end < x2[j]) end = x2[j];
            // cout<<"j :"<<j<<endl;
            // cout<<start<<" ~ "<<end<<endl;
        }
        int d = end  - start;
        //cout<<d<<endl;
        if(minN > d) minN = d;
    }
    cout<<minN;
    return 0;
}