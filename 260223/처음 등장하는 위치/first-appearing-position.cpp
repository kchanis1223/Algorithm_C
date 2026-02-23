#include <iostream>
#include <map>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    map<int,int> m;
    int order = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(m.find(arr[i]) == m.end()) {
            m[arr[i]] = order;
        }
        order ++;
    }
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    // Please write your code here.

    return 0;
}
