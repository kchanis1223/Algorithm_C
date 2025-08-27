#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int arr[1000];

int main() {
    cin >> N >> K;

    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
    }

    // Please write your code here.
    int maxCount = 0;
    for(int i = 0; i<N;i++){
        int min = v[i];
        int count = 1;
        for(int j=i+1;j<N;j++){
            if( abs(v[j] - min) <= K) count +=1;
        }
        if(count > maxCount) maxCount = count;
    }
    cout<<maxCount;
    return 0;
}