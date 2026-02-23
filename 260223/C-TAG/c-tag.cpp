#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int n, m;
string A[500];
string B[500];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    map<vector<int>,set<string>> ms;
    int result =0;
    for(int i=0;i<m-2;i++){
        for(int j=i+1;j<m-1;j++){
            for(int k=j+1;k<m;k++){
                for(int t=0;t<n;t++){
                    string tmp = "";
                    tmp += A[t][i];
                    tmp += A[t][j];
                    tmp += A[t][k];
                    ms[{i,j,k}].insert(tmp);
                }
                bool isValid = true;
                for(int t=0; t<n; t++){
                    string tmp = "";
                    tmp += B[t][i];
                    tmp += B[t][j];
                    tmp += B[t][k];
                    auto it = ms[{i,j,k}].find(tmp);
                    if(it != ms[{i,j,k}].end()){
                        isValid = false;
                        break;
                    }
                }
                if(isValid) result += 1;
            }
        }
    }
    cout<<result;
    // Please write your code here.

    return 0;
}
