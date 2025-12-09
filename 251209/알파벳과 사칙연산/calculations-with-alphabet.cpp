#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int N;
// void backtracking(int idx, vector<int> &v){
//     if(idx == v.size()){
//         total_abcdef.push_back(v);
//         return;
//     }
//     for(int i=idx;i<v.size();i++){
//         v[i]
//     }
// }
int cal(vector<char>alphabets, vector<char> operators, vector<int> abcdef){

    //if(abcdef[0] != 4) return 0;
    map<char,int> m;
    m['a'] = abcdef[0]; m['b'] = abcdef[1]; m['c'] = abcdef[2];
    m['d'] = abcdef[3]; m['e'] = abcdef[4]; m['f'] = abcdef[5];

    // for(auto i : m) cout<<i.first<<"="<<i.second<<" ";
    // cout<<endl;
    
    int cur = m[alphabets[0]];
    for(int i=1;i<=N/2;i++){
        if(operators[i-1] == '+'){
            cur += m[alphabets[i]];
        }
        else if(operators[i-1] == '-'){
            cur -= m[alphabets[i]];
        }
        else{
            cur *= m[alphabets[i]];
        }
        //cout<<"cur :"<<cur<<" ";
    }
    // cout<<endl;
    // cout<<"cal :"<<cur<<endl;
    return cur;
}

int main() {
    // Please write your code here.
    string input;
    cin>>input;
    N = input.size();
    vector<char> alphabets;
    vector<char> operators;
    for(auto i : input){
        if(i == '+' || i =='-' || i =='*' ) operators.push_back(i);
        else {
            alphabets.push_back(i);
        }
    }
    vector<vector<int>> total_abcdef;
    for(int a=1;a<=4;a++){
        for(int b=1;b<=4;b++){
            for(int c=1;c<=4;c++){
                for(int d=1;d<=4;d++){
                    for(int e=1;e<=4;e++){
                        for(int f=1;f<=4;f++){
                            total_abcdef.push_back({a,b,c,d,e,f});
                        }
                    }
                }
            }
        }
    }
    int maxResult = INT_MIN;

    for(auto abcdef : total_abcdef){
        int result = cal(alphabets,operators,abcdef);
        if(maxResult < result) {
            // for(auto i : abcdef) cout<<i;
            // cout<<endl;
            maxResult = result;
        }
    }
    cout<< maxResult;

    return 0;
}