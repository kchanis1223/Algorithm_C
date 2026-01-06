#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n;
int num[20];
int total;
int minValue = INT_MAX;
//vector<int> result;

int cal(vector<int> v){
    int sum = 0;
    for(auto i : v){
        sum += i;
    }
    return sum;
}
void backtracking(vector<int> &v, int idx){
    if(v.size() == n){
        int value = cal(v);
        // cout<<"value : "<< value<<endl;
        // for(auto i : v) cout<<i<<" ";
        // cout<<endl;
        if(abs(total - value - value) < minValue){
            //result = v;
            minValue = abs( total - value - value);
        }
        return;
    }
    for(int i = idx; i<2*n;i++){
        v.push_back(num[i]);
        backtracking(v,i+1);
        v.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> num[i];
        total += num[i];
    }

    // Please write your code here.
    vector<int> v= {};
    backtracking(v,0);
    cout<<minValue;
    return 0;
}
