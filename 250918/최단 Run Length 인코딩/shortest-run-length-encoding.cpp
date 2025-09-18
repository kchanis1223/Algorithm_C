#include <iostream>
#include <string>
#include <vector>

using namespace std;

string A;
string Shift(int n){
    string tmp1 ="";
    string tmp2 ="";
    for(int i=0;i<A.size()-n;i++){
        tmp1 += A[i];
    }
    for(int i=A.size()-n;i<A.size();i++){
        tmp2 += A[i];
    }
    return tmp2 + tmp1;
}

int main() {
    cin >> A;

    // Please write your code here.

    vector<int> min_v(100);
    for(int shift=0; shift<A.size(); shift++){
        string s = Shift(shift);
        //cout<<s<<endl;
        char cur = s[0];
        int count = 1;
        vector<int> v;
        for(int i=1;i<A.size(); i++){
            if(s[i] == cur ){
                count +=1;
                if(i == A.size()-1 ) v.push_back(count);
            }
            else{
                v.push_back(count);
                count = 1;
                cur = s[i];
                if(i == A.size()-1 ) v.push_back(count);
            }
        }
        // for(auto i : v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        if(v.size() < min_v.size()) min_v = v;
    }
    int count = 0;
    for(auto num : min_v){
        if(num >= 10) count += 3;
        else count +=2;
    }
    if(A.size() == 1) cout<<2;
    else cout<<count;
    return 0;
}
