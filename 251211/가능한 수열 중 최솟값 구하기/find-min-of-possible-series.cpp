#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int n;
vector<string> result;

bool IsValid(string str){
    for(int i=1;i<str.size();i++){
        string str1 = str.substr(0,i);
        string str2 = str.substr(i);

        set<string> s1;
        for(int j =0; j< str1.size();j++){
            s1.insert(str1.substr(j));
        }
        if( s1.find(str2) != s1.end()) return false; 
    }
    return true;
}

void backtracking(string &str){
    
    if(str.size() == n){
        result.push_back(str);
        return;
    }

    str += '4';
    if( IsValid(str) ) backtracking(str);
    str.pop_back();

    str += '5';
    if( IsValid(str) ) backtracking(str);
    str.pop_back();

    str += '6';
    if( IsValid(str) ) backtracking(str);
    str.pop_back();
    
}

int main() {
    cin >> n;
    // Please write your code here.
    string str = "";
    cout<<str.substr(0,0);
    backtracking(str);
    sort(result.begin(),result.end());
    cout<<result[0];
    return 0;
}
