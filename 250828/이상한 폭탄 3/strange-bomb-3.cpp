#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int num[100];

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    int maxCount = 0;
    vector<int> v;
    for(int i=0;i<N-1;i++){
        int number = num[i];
        int count = 1;
        for(int j=i+1;j<=i+K && j< N; j++){
            if(num[j] == number) count +=1;
        }
        //cout<<"i :"<<i<<", count :"<<count<<endl;
        if(count == 1) continue;
        if(maxCount < count){
            maxCount = count;
            v = {number};
        }
        else if(maxCount == count){
            v.push_back(number);
        }
    }
    if(!v.empty()) cout<< *max_element(v.begin(),v.end());
    else cout<<0;
    // Please write your code here.

    return 0;
}