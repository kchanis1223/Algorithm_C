#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
int numbers[1000];

int main() {
    cin >> N;
    multiset<int> ms;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        ms.insert( (numbers[i] % 2 != 0 ?1:0) );
    }
    int prev_state = 1;
    bool isValid = true;
    int count = 0;
    // for(auto i : ms){
    //     cout<< i<<" ";
    // }
    // cout<<endl;
    while(!ms.empty()){
        if(prev_state == 1){
            auto it = ms.find(0);
            if(it != ms.end()){
                ms.erase(it);
            }
            else{
                if(ms.size() < 2){
                    isValid = false;
                    break;
                }
                ms.erase(ms.begin());
                ms.erase(ms.begin());
            }
            prev_state = 0;
            //cout<<" even count++"<<endl;
            count +=1;
        }
        else{
            auto it = ms.find(1);
            if(it == ms.end()){
                isValid = false;
                break;
            }
            ms.erase(it);
            prev_state = 1;
            //cout<<"odd count++"<<endl;
            count +=1;
        }
    }
    if(isValid) cout << count ;
    else cout<< count-1;

    return 0;
}