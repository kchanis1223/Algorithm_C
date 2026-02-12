#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, k;
int arr[100000];

map<int,int> m; // 값,인덱스
int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]] = i+1;
    }
    int result = 0;
    for(int i=0;i<n;i++){
        if(m[k - arr[i]] != 0 && m[k - arr[i]] != i+1) {
            //cout<<i<<endl;
            result += 1;
        }
    }
    cout<<result/2;

    // Please write your code here.

    return 0;
}
