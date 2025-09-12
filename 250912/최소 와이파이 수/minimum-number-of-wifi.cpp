#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    int count = 0;
    int wifi = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == 1 ){
            if(i > wifi +m || wifi < 0){
                wifi = i + m;
                count +=1;
            }
        }
    }
    cout<<count;
    return 0;
}