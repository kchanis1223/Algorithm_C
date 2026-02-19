#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n;
int x[100000], y[100000];

int main() {
    cin >> n;
    map<long long,long long> m;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if( m[x[i]] == 0 ) m[x[i]] = y[i];
        else{
            if(m[x[i]] > y[i]) m[x[i]] = y[i];
        }
    }
    long long sum =0;
    for(auto i : m){
        //cout<<i.first<<","<<i.second<<endl;
        sum += i.second;
    }
    cout<<sum;
    // Please write your code here.

    return 0;
}