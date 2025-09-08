#include <iostream>
#include <climits>
using namespace std;

int X;

int main() {
    cin >> X;

    // Please write your code here.

    int minTime =INT_MAX;
    for(int speedLimit=1;speedLimit<=1000; speedLimit++){
        bool isValid = true;
        int cur =0;
        int spendTime =0;
        int speed =1;
        while(speed < speedLimit){
            cur += speed;
            spendTime +=1;
            speed +=1;
            if(cur > X) {
                isValid = false;
                break;
            }
        }
        while(speed > 1){
            cur += speed;
            spendTime +=1;
            speed -= 1;
            if(cur > X) {
                isValid = false;
                break;
            }
        }
        if(! isValid) continue;

        spendTime += X - cur;
        //cout<<"speedLimit :"<<speedLimit<<" / spendTime :"<<spendTime<<endl;
        if(minTime > spendTime) minTime = spendTime;
    }
    cout<<minTime;
    return 0;
}