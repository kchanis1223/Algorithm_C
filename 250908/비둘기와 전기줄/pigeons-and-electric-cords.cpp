#include <iostream>
#include <map>

using namespace std;

int N;
int pigeon[100];
int position[100];

int main() {
    cin >> N;
    map<int,int> m;
    for (int i = 0; i < N; i++) {
        cin >> pigeon[i] >> position[i];
    }

    // Please write your code here.
    int count = 0;
    for(int i=0;i<N;i++){
        if(m.find(pigeon[i]) == m.end()){
            m[pigeon[i]] = position[i];
        }
        else if(position[i] != m[pigeon[i]]){
            //cout<<i<<endl;
            m[pigeon[i]] = position[i];
            count +=1;
        }
    }
    cout<<count;
    return 0;
}