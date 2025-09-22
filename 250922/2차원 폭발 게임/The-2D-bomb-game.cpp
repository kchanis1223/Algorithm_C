#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int numbers_2d[100][100];

void explode(){
    vector<vector<int>> tmp = vector<vector<int>>(N,vector<int>(N,-1));
    for(int i=0;i<N;i++){
        vector<int> v;
        vector<int> continues;
        for(int j=0;j<N;j++){
            if(continues.empty() || numbers_2d[N-1-j][i] == continues[0] && j != 0 ) continues.push_back(numbers_2d[N-1-j][i]);
            else if (j != 0){
                if(continues.size() < M){
                    for(auto k : continues){
                        v.push_back(k);
                    }
                }
                
                continues = {numbers_2d[N-1-j][i]};
            }
            else if(j == 0){
                if(numbers_2d[N-1-j][i] == continues[0]) continues.push_back(numbers_2d[N-1-j][i]);
                if(continues.size() < M){
                    for(auto k : continues){
                        v.push_back(k);
                    }
                }
                
            }
        }
        while(continues.size() == N) continues.push_back(0);
        for(int j=0;j<N;j++){
            tmp[N-1-j][i] = continues[j];
        }
    }
    for(int i=0; i <N;i++){
        for(int j = 0 ;j<N;j++){
            numbers_2d[i][j] = tmp[i][j];
        }
    }

}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers_2d[i][j];
        }
    }
    for(int repeat ; repeat < K; repeat++){
        explode();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<< numbers_2d[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        //rotate();
    }
    explode();
    int count = 0;
    for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(numbers_2d[i][j] != 0) count +=1;
            }
        }
    cout<<count;

    // Please write your code here.

    return 0;
}
