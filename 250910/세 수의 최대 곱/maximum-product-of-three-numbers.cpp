#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    vector<int> positive;
    vector<int> negative;
    vector<int> result; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] >= 0)positive.push_back(arr[i]);
        else negative.push_back(arr[i]);
    }
    sort(positive.begin(),positive.end());
    sort(negative.begin(),negative.end());
    
    if(positive.size() == 0){
        int end = negative.size();
        cout<< negative[end-1] * negative[end-2] * negative[end-3];
    }
    else if(positive.size() == 1) {
        cout<< negative[0] * negative[1] * positive[0];
    }
    else if(positive.size() == 2){
        if(negative.size() > 1) cout<< negative[0] * negative[1] * positive[1];
        else cout<< negative[0] * positive[0] * positive[1];
    }
    else{
        int posEnd = positive.size();
        if( negative[0] * negative[1] >= positive[posEnd-2] * positive[posEnd-3] ) cout<< negative[0] * negative[1] * positive[posEnd-1] ;
        else cout<< positive[posEnd-1] * positive[posEnd-2] * positive[posEnd-3];

    }



    // Please write your code here.

    return 0;
}