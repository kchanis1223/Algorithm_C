#include <iostream>

using namespace std;

int n, m;
int a[100], b[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    // Please write your code here.
    int maxCount = 0;
    for(int i=0;i<m;i++){
        int count = 1;
        int x = a[i];
        int y = b[i];
        for(int j=0;j<m &&j !=i;j++){
            if( (a[j] == x && b[j] == y )||(b[j] == x && a[j] == y ) ) count +=1;
        }
        if(maxCount < count) maxCount = count;
    }
    cout<<maxCount;
    return 0;
}