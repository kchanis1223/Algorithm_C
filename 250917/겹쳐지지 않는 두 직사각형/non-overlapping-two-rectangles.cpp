#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
int grid[5][5];

bool checkRange(int x, int y, int r, int c){
    if( x + r >= n || y + c >= m) return false;
    return true;
}
int calSquare(int x, int y, int r, int c){
    int sum =0;
    for(int i = x;i<=x+r;i++){
        for(int j =y;j<y+c;j++){
            sum += grid[i][j];
        }
    }
    return sum;
}
bool checkValid(int x , int y , int r, int c, vector<vector<bool>> &visited){
    for(int i = x; i <=x+r;i++){
        for(int j=y; j<=y+c; j++){
            if ( visited[i][j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> v;
    int maxSum = INT_MIN;
    for(int i1=0;i1<n;i1++){
        for(int j1=0;j1<m;j1++){
            for(int r1 = 0; r1<n; r1++){
                for(int c1 =0; c1<m; c1++){
                    if(checkRange(i1,j1,r1,c1)) {
                        vector<vector<bool>> visited = vector<vector<bool>>(n,vector<bool>(m,false));
                        int sum1 = 0;
                        for(int i=i1; i<=i1+r1; i++){
                            for(int j=j1; j<=j1+c1; j++){
                                visited[i][j] = true;
                                sum1 += grid[i][j];
                            }
                        }
                        for(int i2=0;i2<n;i2++){
                            for(int j2=0;j2<m;j2++){
                                for(int r2 = 0; r2<n; r2++){
                                     for(int c2 =0; c2<m; c2++){
                                        if(checkRange(i2,j2,r2,c2) && checkValid(i2,j2,r2,c2,visited)) {
                                            int sum2 =0;
                                            for(int i=i2;i<=i2+r2;i++){
                                                for(int j=j2;j<=j2+c2;j++){
                                                    sum2 += grid[i][j];
                                                }
                                            }
                                            if(maxSum < sum1 + sum2) {
                                                maxSum = sum1 + sum2;
                                                // cout<<i1<<","<<j1<<","<<r1<<","<<c1<<endl;
                                                // cout<<i2<<","<<j2<<","<<r2<<","<<c2<<endl;
                                                // cout<<"sum1 :"<<sum1<< " sum2 : "<<sum2<<endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        
                    }
                }
            }
        }
    }
    cout<<maxSum;

    // Please write your code here.

    return 0;
}
