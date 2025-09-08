#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
char arr[26];

int main() {
    cin >> n;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s="";
    string result="";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
        result += alphabet[i];
    }

    // Please write your code here.
    int count =0;
    for(int i=0;i<n;i++){
        //cout<<s<<endl;
        char c = alphabet[i];
        int idx = int(s.find(c));
        for(int j = idx; j >= i+1;j--){
            auto it = s.begin() + j;
            iter_swap(it,it-1);
            count +=1;
        }
    }
    cout<<count;
    
    return 0;
}