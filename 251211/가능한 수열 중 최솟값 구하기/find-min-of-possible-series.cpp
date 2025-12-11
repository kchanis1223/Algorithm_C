#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int n;
bool isFind = false;
map<string, set<string>> m;

bool IsValid(string str){
    for(int i=1;i<str.size();i++){
        string str1 = str.substr(0,i);
        string str2 = str.substr(i);

        set<string> s1;
        if(m.find(str1) == m.end() ){
            for(int j =0; j< str1.size();j++){
                s1.insert(str1.substr(j));
            }
            m[str1] = s1;
        }
        else{
            s1 = m[str1];
        }
        if( s1.find(str2) != s1.end()) return false; 
    }
    return true;
}

void backtracking(string &str){
    if(isFind) return;
    if(str.size() == n){
        isFind = true;
        cout<<str;
        return;
    }

    if(str.back() != '4'){
        str += '4'; 
        if( IsValid(str)) { 

            backtracking(str);
        } 
        str.pop_back();
    }
    if(str.back() != '5'){
        str += '5'; 
        if( IsValid(str)) { 
            backtracking(str);
        } 
        str.pop_back();
    }
    if(str.back() != '6'){
        str += '6'; 
        if( IsValid(str)) { 
            backtracking(str);
        } 
        str.pop_back();
    }


}

int main() {
    cin >> n;
    // Please write your code here.
    string str0 = "";
    // string str1="45464564654564546456465"; //23
    // string str2="4546456465456454645646546454654564546456465456";//46
    // string str3="454645646545645464564654645465456454645646545645465456465464546545645";//69
    // if(n < 23) backtracking(str0);
    // else if (n <46) backtracking(str1);
    // else if(n < 69) backtracking(str2);
    // else backtracking(str3);
    // for(auto i : result){
    //     cout<<i<<endl;
    // }
    backtracking(str0);
    return 0;
}
