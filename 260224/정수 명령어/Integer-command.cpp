#include <iostream>
#include <set>

using namespace std;

int T;
int k;
char command[100000];
int n[100000];

int main() {
    cin >> T;

    for (int t = 0; t < T; t++) {
        set<int> s;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> command[i] >> n[i];
            if(command[i] == 'I') s.insert(n[i]);
            else if (command[i] == 'D' && n[i] == 1 && !s.empty() ) s.erase(*s.rbegin());
            else if(command[i] == 'D' && n[i] == -1 && !s.empty() ) s.erase( *s.begin());
        }
        if(!s.empty()) cout<< *s.rbegin()<<" "<<*s.begin()<<endl;
        else cout<<"EMPTY"<<endl;

    
    // Please write your code here.

    }

    return 0;
}
