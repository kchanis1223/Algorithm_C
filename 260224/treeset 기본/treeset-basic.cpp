#include <iostream>
#include <set>

using namespace std;

// 변수 선언
int n;
set<int> s;

int main() {
    // 입력:
    cin >> n;

    for(int i = 0; i < n; i++) {
        string command;
        cin >> command;

        int x;

        if(command == "add") {
            cin >> x;
            s.insert(x);
        }
        else if(command == "remove") {
            cin >> x;
            s.erase(x);
        }
        else if(command == "find") {
            cin >> x;
            if(s.find(x) != s.end())
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else if(command == "lower_bound") {
            cin >> x;
            if(s.lower_bound(x) != s.end())
                cout << *s.lower_bound(x) << endl;
            else
                cout << "None" << endl;
        }
        else if(command == "upper_bound") {
            cin >> x;
            if(s.upper_bound(x) != s.end())
                cout << *s.upper_bound(x) << endl;
            else
                cout << "None" << endl;
        }
        else if(command == "largest") {
            if(s.rbegin() != s.rend())
                cout << *s.rbegin() << endl;
            else
                cout << "None" << endl;
        }
        else {
            if(s.begin() != s.end())
                cout << *s.begin() << endl;
            else
                cout << "None" << endl;
        }
    }
    return 0;
}
