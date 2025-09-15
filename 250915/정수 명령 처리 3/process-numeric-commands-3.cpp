#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N;
string cmd[10000];
int num[10000];

int main() {
    cin >> N;
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        cin >> cmd[i];
        if (cmd[i] == "push_front" || cmd[i] == "push_back") {
            cin >> num[i];
            if(cmd[i] == "push_front") dq.push_front(num[i]);
            else dq.push_back(num[i]);
        }
        if(cmd[i] == "pop_front") {
            cout<< dq.front()<<endl;
            dq.pop_front();
        }
        if(cmd[i] == "pop_back") {
            cout<< dq.back()<<endl;
            dq.pop_back();
        }
        if(cmd[i] == "size") cout<< dq.size()<<endl;
        if(cmd[i] == "empty") cout<< (dq.empty()?1:0)<<endl;
        if(cmd[i] == "front") cout<< dq.front()<<endl;
        if(cmd[i] == "back") cout<< dq.back()<<endl; 
    }

    // Please write your code here.

    return 0;
}
