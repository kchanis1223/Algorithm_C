#include <iostream>
#include <vector>
using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

int main() {
    cin >> n >> t;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        v.push_back(l[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        v.push_back(r[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        v.push_back(d[i]);
    }
    t %= 3*n;

    vector<int> tmp1 = vector<int>(v.begin(),v.end()-t);
    vector<int> tmp2 = vector<int>(v.end()-t,v.end());
    for(auto i : tmp1){
        tmp2.push_back(i);
    }
    for(int i=0;i<3*n;i++){
        cout<<tmp2[i]<<" ";
        if(i == n-1 || i == 2*n-1)cout<<endl;
    }
    // Please write your code here.

    return 0;
}
