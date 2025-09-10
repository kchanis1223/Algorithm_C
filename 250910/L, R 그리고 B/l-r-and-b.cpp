#include <iostream>

using namespace std;

char board[10][10];

int main() {
    int Lx,Ly;
    int Bx,By;
    int Rx,Ry;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'L') {
                Lx = i ; Ly = j;
            }
            if(board[i][j] == 'B'){
                Bx = i ; By =j;
            }
            if(board[i][j] == 'R'){
                Rx = i ; Ry =j;
            }
        }
    }
    if(Lx == Bx && Lx == Rx){
        if( (Ly < Ry && Ry < By) || (By < Ry && Ry < Ly)  ){
            cout<< abs(Ly-By) + 1;
        }
        else cout<< abs(Ly-By) -1;
    }
    else if(Ly == By && Ly == Ry){
        if( (Lx < Rx && Rx < Bx) || (Bx < Rx && Rx < Lx)  ){
            cout<< abs(Lx-Bx) + 1;
        }
        else cout<< abs(Lx-Bx) -1;
    }
    else{
        cout<< abs(Bx-Lx) + abs(By - Ly) -1;
    }
    return 0;
}