#include <iostream>
#include <vector>

using namespace std;

int n, m;
int grid[200][200];

void explode(int r, int c){
    int range = grid[r][c]-1;
    //cout<<"range : "<<range<<endl;
    for(int i= r-range; i<= r+ range; i++){
        grid[i][c] = 0;
    }
    for(int i = c-range; i<= c+range; i++){
        grid[r][i] = 0;
    }
}
void gravity(){
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            if(grid[n-1-j][i] == 0) continue;
            v.push_back(grid[n-1-j][i]); 
        }
        while(v.size() < n) v.push_back(0);
        for(int j=0;j<n;j++){
            grid[n-1-j][i] = v[j];
        }
    }
}
void apply(int c){
    int r = -1;
    
    for(int i=0;i<n;i++){
       if(grid[i][c] != 0) {
        r = i;
        break;
       }
    }
    explode(r,c);
    gravity();
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int t = 0; t < m; t++) {
        int c;
        cin >> c;
        apply(c-1);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    // Please write your code here.

    return 0;
}
