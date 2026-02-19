#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, k;
int arr[100000];

int main() {
    cin >> n >> k;
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]] += 1;
    }
    map<int,vector<int>> cm;
    for(auto [value,count] : m){
        //cout<<value<<endl;
        cm[count].push_back(value);
    }

    vector<int> result;
    for(auto [count,v] : cm){
        for(auto value : v){
            result.push_back(value);
        }
    }
    for(int i =0; i<k;i++){
        cout<< result[result.size() - i -1]<<" ";
    }
    
    // Please write your code here.

    return 0;
}
