#include <iostream>
#include <string>

using namespace std;

int N;
string seat;

int main() {
    cin >> N;
    cin >> seat;

    // Please write your code here.
    int result = 0;
    for(int i=0;i<N-1;i++){
        if(seat[i] == '1') continue;
        string tmp1 = seat;
        tmp1[i] = '1';
        for(int j=i+1;j<N;j++){
            if(tmp1[j] == '1')continue;
            string tmp2 = tmp1;
            tmp2[j] = '1';

            int minCount = N;
            int count =1;
            bool flag = false;
            for(int k=0;k<N;k++){
                if(tmp2[k] == '1' && k != 0){
                    if(minCount > count) minCount = count;
                    count =1;
                    continue;
                }
                else if (tmp2[k] == '0') count +=1;
            }
            //cout<<tmp2<<endl;
            //cout<< "minCount :"<<minCount<<endl;
            if(result < minCount) result = minCount;
        }
        
    }
    cout<<result;
    return 0;
}