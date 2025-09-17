#include <iostream>
#include <vector>
using namespace std;

int n, m;
int grid[20][20];

bool checkRange(int x , int y){
    if(x>= 0 && x < n && y >= 0 && y < n) return true;
    return false;
}
int checkGrid(int x , int y, int k){
    int count =0;
    for(int i= -k;i<=k;i++){
        for(int j= -k;j<=k;j++){
            if( abs(i) + abs(j) > k) continue;
            if( checkRange(x+i,y+j)) count +=1;
        }
    }
    return count;
}
int checkGold(int x , int y, int k){
    int count =0;
    for(int i= -k;i<=k;i++){
        for(int j= -k;j<=k;j++){
            if( abs(i) + abs(j) > k) continue;
            if( checkRange(x+i,y+j) && grid[x+i][y+j] == 1) count +=1;
        }
    }
    return count;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    for(int x =0;x<n;x++){
        for(int y=0;y<n;y++){
            int subMax =0;
            //cout<<"x :"<<x<<" , y :"<<y<<endl;
            for(int k = 0;k<n;k++){
                //int cost = checkGrid(x,y,k);
                int cost = k*k + (k+1)*(k+1);
                int gold = checkGold(x,y,k);
                if( gold * m >= cost && subMax < gold) {
                    subMax = gold;
                    //cout<<"x :"<<x<<" , y :"<<y<<endl;
                    //cout<<"k :"<<k<< " cost :"<<cost<<" / gold : "<<gold<<endl;
                }
                //cout<<"k :"<<k<< " cost :"<<cost<<" / gold : "<<gold<<endl; 
            }
            if(subMax > result) result = subMax;
        }
    }
    cout<<result;
    // Please write your code here.

    return 0;
}
