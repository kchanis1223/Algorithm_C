#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string seats;

int main() {
    cin >> N;
    cin >> seats;

    // Please write your code here.
    int maxCount =0;
    for(int i=0; i<N;i++){
        
        if(seats[i] == '1') continue;
        string tmp = seats;
        vector<int> v;
        tmp[i] = '1';

        int count =0;
        int flag= false;
        for(int j=0;j<N;j++){
            if(tmp[j] =='1' && !flag){
                flag = true; 
            }
            else if(tmp[j] == '1' && flag){
                v.push_back(count);
                count = 0;      
            }
            else if(tmp[j] == '0'){
                count +=1;
            }
        }
        maxCount = max(maxCount , *min_element(v.begin(),v.end()) +1 );
    }
    cout<<maxCount;
    return 0;
}