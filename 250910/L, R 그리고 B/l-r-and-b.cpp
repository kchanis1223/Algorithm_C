#include <iostream>

using namespace std;

char board[10][10];

int main() {
    int Lx,Ly;
    int Bx,By;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'L') {
                Lx = i ; Ly = j;
            }
            if(board[i][j] == 'B'){
                Bx = i ; By =j;
            }
        }
    }

    // Please write your code here.
    cout<< abs(Bx-Lx) + abs(By - Ly) -1;
    return 0;
}