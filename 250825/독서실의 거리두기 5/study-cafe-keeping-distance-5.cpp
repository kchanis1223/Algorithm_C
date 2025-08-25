#include <iostream>
#include <string>

using namespace std;

int N;
string seat;

int main() {
    cin >> N;
    cin >> seat;

    // Please write your code here.
    int result = 0;
    for(int i=0;i<seat.size();i++){
        string tmp = seat;
        if(tmp[i] == '1') continue;
        tmp[i] = '1';
        
        // cout<<"insert in "<<i<<endl;
        // for(int j=0;j<tmp.size();j++){
        //     cout<<tmp[j]<<" ";
        // }
        // cout<<endl;

        int minDis = 20;
        int count= 0;
        bool flag = false;
        for(int j=0;j<tmp.size();j++){
            if(tmp[j] == '0') {
                count +=1;
                //cout<<"count : "<<count<<endl;
                }
            else {
                if(count < minDis && flag) {
                    minDis = count;
                    //cout<<"minDis "<<minDis<<endl;
                }
                flag = true;
                count = 0;
                
            }
        }
        //cout<<minDis<<endl;
        if(minDis > result ) result = minDis;
    }
    cout<<result+1;
    return 0;
}