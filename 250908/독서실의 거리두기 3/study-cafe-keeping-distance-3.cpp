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
        seats[i] = '1';
        vector<int> v;
        int count = 0;
        for(int j=0;j<seats.size();j++){
            if(seats[j] == '1' && j != 0) {
                v.push_back(count);
                count =0;
            }
            else{
                count +=1;
            }
        }
        
        maxResult = max(*min_element(v.begin(),v.end()) + 1 , maxResult);
    }
    cout<<maxResult;
    return 0;
}