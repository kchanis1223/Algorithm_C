#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
int A[5000];
int B[5000];
int C[5000];
int D[5000];

int main() {
    cin >> n;

    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    for (int i = 0; i < n; i++) {cin >> A[i]; a.push_back(A[i]);}

    for (int i = 0; i < n; i++) {cin >> B[i]; b.push_back(B[i]);}

    for (int i = 0; i < n; i++) {cin >> C[i]; c.push_back(C[i]);}

    for (int i = 0; i < n; i++) {cin >> D[i]; d.push_back(D[i]);}

    // Please write your code here.
    map<long long,int> AB;
    for(auto i : a){
        for(auto j : b){
            AB[i+j] ++;
        }
    }

    map<long long,int> ABC;
    for(auto [value,count]: AB){
        for(auto j :c){
            ABC[value + j] += count;
        }
    }

    map<long long,int> ABCD;
    for(auto [value,count] : ABC){
        for(auto j :d){
            ABCD[value + j] += count;
        }
    }

    cout<<ABCD[0];
    return 0;
}
