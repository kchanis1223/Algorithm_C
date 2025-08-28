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
    vector<int> idx;
    for(int i=0;i<N-1;i++){
        int number = num[i];
        int count = 1;
        for(int j=i+1;j<=i+K;j++){
            if(num[j] == number) count +=1;
        }
        //cout<<"i :"<<i<<", count :"<<count<<endl;
        if(maxCount < count){
            maxCount = count;
            idx = {i+1};
        }
        else if(maxCount == count){
            idx.push_back(i+1);
        }
    }
    cout<< *max_element(idx.begin(),idx.end());
    // Please write your code here.

    return 0;
}