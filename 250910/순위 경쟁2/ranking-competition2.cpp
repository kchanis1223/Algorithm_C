#include <iostream>

using namespace std;

int n;
char c[100];
int s[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> s[i];
    }

    int scoreA = 0;
    int scoreB = 0;
    int state = 0; //0 : 둘다 / 1 :A 2 :B
    int count = 0;
    for(int i=0;i<n;i++){
        if(c[i] == 'A') scoreA += s[i];
        else scoreB += s[i];

        if(scoreA == scoreB && state != 0){
            state = 0;
            count +=1;
        } 
        else if(scoreA > scoreB && state != 1){
            state = 1;
            count += 1;
        }
        else if(scoreA < scoreB && state != 2){
            state = 2;
            count += 1;
        }
    }
    // Please write your code here.
    cout<<count;
    return 0;
}