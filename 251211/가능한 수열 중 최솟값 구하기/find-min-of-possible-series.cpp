#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

int n;
vector<string> result;
map<string, set<string>> m;

bool IsValid(string str){
    //cout<<"isValid str : "<<str<<endl;
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
    //cout<<"isValid str : "<<str<<" is true"<< endl;
    return true;
}

void Nxt(int t){
    string str = result[t];
    if(str.back() != '4' ){
        str += '4';
        if(IsValid(str)) {
            result.push_back(str);
            return;
        }
        str.pop_back();
    }
    if(str.back() != '5' ){
        str += '5';
        if(IsValid(str)) {
            result.push_back(str);
            return;
        }
        str.pop_back();
    }
    str += '6';
    result.push_back(str);
    return;
}

int main() {
    cin >> n;
    // Please write your code here.
    result.push_back("4");
    for(int i=0;i<81;i++){
        Nxt(i);
    }
    cout<<result[n-1];
    return 0;
}
