#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[100];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int maxSum = 0;
    for(int i=1;i<=n;i++){
        int sum = arr[i];
        int cur = arr[i];
        for(int j=0;j<m-1;j++){
            //cout<<cur<<" ";
            cur = arr[cur];
            sum += cur;
        }
        //cout<<endl;
        //cout<<"sum :"<<sum<<endl;
        if(maxSum < sum) maxSum = sum;
    }
    cout<<maxSum;    // Please write your code here.

    return 0;
}