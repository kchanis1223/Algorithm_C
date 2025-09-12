#include <iostream>
#include <vector>

using namespace std;

int N;
int numbers[1000];

int main() {
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        v.push_back( (numbers[i] % 2 != 0 ?1:0) );
    }

    // Please write your code here.
    int count = 0;
    int group_state = 0;
    int prev_state = 1; // 0이면 이전 상태 짝수 
    for(int i=0;i<N;i++){
        int remain_state = -1;
        for(int j=i+1;j<N;j++){
            if(remain_state == -1) remain_state =0;
            remain_state += v[j];
            remain_state %=2;
        }
        group_state += v[i];
        group_state %= 2;
        //cout<<i<<endl;
        //cout<<"prev:"<<prev_state<<" group :"<<group_state<<" remain:"<<remain_state<<endl;
        if(group_state != prev_state && remain_state != group_state && remain_state != -1){
            //cout<<"count++"<<endl;
            //cout<<"i :"<<i<< "  group_state :"<<group_state<<endl;
            prev_state = group_state;
            group_state = 0;
            count +=1;
        }
        
    }
    cout<<count + 1;
    return 0;
}