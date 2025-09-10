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

    // Please write your code here.
    int count = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    int state = 0; // ABC , AB , AC , BC , A , B , C
    for(int i=0;i<n;i++){
        if(c[i] == 'A') A += s[i];
        if(c[i] == 'B') B += s[i];
        if(c[i] == 'C') C += s[i];

        if(A==B && B==C && state != 0){
            count +=1;
            state = 0;
        }
        else if(A==B && A>C && state != 1){
            count +=1;
            state = 1;
        }
        else if(A==C && A>B && state != 2){
            count +=1;
            state = 2;
        }
        else if(B==C && B>A && state != 3){
            count +=1;
            state = 3;
        }
        else if(C>B && C>A && state != 4){
            count +=1;
            state = 4;
        }
        else if(A>B && A>C && state != 5){
            count +=1;
            state = 5;
        }
        else if(B>A && B>C && state != 6){
            count +=1;
            state = 6;
        }
    }
    cout<<count;
    return 0;
}