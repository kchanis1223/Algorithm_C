#include <iostream>
#include <vector>
using namespace std;

int n, k;
int arr[100];

int main() {
    cin >> n >> k;
    vector<int> v;
    v.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    // Please write your code here.
    for(int max = 1; max<=100; max++){
        int cur = 0;
        if(v[cur] > max) continue;
        bool isValid = false;
        while(cur<=n){
            bool flag = false;
            if(cur + k >= n) 
            {
                isValid = true;
                break;
            }
            for(int i=1;i<=k;i++){
                if(v[cur+i] <= max) {
                    cur += i;
                    flag = true;
                    break;
                }
            }
            if(!flag) break;
        }
        if(isValid){
            cout<<max;
            break;
        }
    }
    return 0;
}