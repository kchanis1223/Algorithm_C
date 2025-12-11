#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int num[10];

int minCount = INT_MAX;
void Jump(int x, int count){
    if(x == n-1){
        if(count < minCount) minCount = count;
        return;
    }
    for(int i=1;i<=num[x];i++){
        if(x+i <n) Jump(x+i, count +1);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    Jump(0,0);
    minCount != INT_MAX ? cout<<minCount : cout<<-1;
    // Please write your code here.

    return 0;
}
