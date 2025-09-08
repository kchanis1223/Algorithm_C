#include <iostream>
#include <climits>
using namespace std;

int X;

int main() {
    cin >> X;

    // Please write your code here.

    int minTime = INT_MAX;
    for(int up = 1; up<300;up++){
        for(int down = up; down <300;down++){
            for(int maintain = down; maintain <300; maintain++){
                bool isValid = true;
                int speed = 1;
                int cur = 0;
                int time = 0;

                while(time < up){
                    cur += speed;
                    speed ++;
                    time ++;
                    if(cur > X){
                        isValid = false;
                        break;
                    }
                }
                while(time < down){
                    cur += speed;
                    speed--;
                    time ++;
                    if(cur > X){
                        isValid = false;
                        break;
                    }
                }
                while(time < maintain){
                    cur += speed;
                    time ++;
                    if(cur > X){
                        isValid = false;
                        break;
                    }
                }
                while(speed > 1){
                    cur += speed;
                    speed --;
                    time ++;
                    if(cur > X){
                        isValid = false;
                        break;
                    }
                }
                if(!isValid) continue;
                time += X - cur + 1;
                if(minTime >time) minTime = time;
            }
        }
    }
    cout << minTime << '\n';
    return 0;
}