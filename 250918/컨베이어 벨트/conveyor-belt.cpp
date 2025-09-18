#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N,T;
    cin>>N>>T;
    vector<int> v1;
    for(int i=0;i<2*N;i++){
        int input;
        cin>>input;
        v1.push_back(input);
    }
    T %= 2*N;
    vector<int> tmp1 = vector<int>(v1.begin(),v1.end()-T);
    vector<int> tmp2 = vector<int>(v1.end()-T,v1.end());
    for(auto i : tmp1){
        tmp2.push_back(i);
    }
    for(int i=0;i<tmp2.size();i++){
        cout<<tmp2[i]<<" ";
        if(i == N-1)cout<<endl;
    }
    return 0;
}