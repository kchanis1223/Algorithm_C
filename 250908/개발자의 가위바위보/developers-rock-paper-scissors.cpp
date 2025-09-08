#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int a[100], b[100];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    vector<string> v = {"xrsp","xrps","xsrp","xspr","xpsr","xprs"}; 

    int maxCount = 0;
    for(auto str : v){
        int count = 0;
        for(int i=0;i<N;i++){
            if(str[a[i]] == 'r' && str[b[i]] == 's') count += 1;
            else if(str[a[i]] == 's' && str[b[i]] == 'p') count += 1;
            else if(str[a[i]] == 'p' && str[b[i]] == 'r') count += 1;
        }
        if(maxCount < count) maxCount = count;
    }
    cout<<maxCount;
    // Please write your code here.

    return 0;
}