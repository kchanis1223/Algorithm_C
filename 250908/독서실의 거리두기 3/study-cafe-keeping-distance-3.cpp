#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string seats;

int main() {
    cin >> N;
    cin >> seats;

    // Please write your code here.
    int maxResult = 0;
    for(int i=0;i<N;i++){
        if(seats[i] == '1') continue;
        string tmp = seats;
        tmp[i] = '1';
        vector<int> v;
        int count = 0;
        for(int j=0;j<seats.size();j++){
            if(tmp[j] == '1' && j != 0) {
                v.push_back(count);
                count =0;
            }
            else if (tmp[j] == '0'){
                count +=1;
            }
        }
        // cout<<tmp<<endl;
        // for(auto i : v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
        maxResult = max(*min_element(v.begin(),v.end()) + 1 , maxResult);
    }
    cout<<maxResult;
    return 0;
}