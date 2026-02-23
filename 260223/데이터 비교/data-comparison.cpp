#include <iostream>
#include <map>
using namespace std;

int n, m;
int arr1[100000];
int arr2[100000];

int main() {
    cin >> n;
    map<int,bool> m1;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        m1[arr1[i]] = true;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        if(m1.find(arr2[i]) != m1.end()){
            cout<<"1"<<" ";
        }
        else cout<<"0"<<" ";
    }

    // Please write your code here.

    return 0;
}
