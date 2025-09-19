#include <iostream>
#include <vector>

using namespace std;

int n, m;
int numbers[100];

void apply(vector<int> &v){
    vector<int> result;

    for(int i=0;i<v.size();){
        int curN = v[i];
        int count = 1;
        
        for(int j=i+1;j<v.size();j++){
            if(curN == v[j]){
                count +=1;
            }
            else break;
        }
        if(count < m) result.push_back(curN);
        i += count;
    }
    v = result;
}

int main() {
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for(int i=0;i<n;i++){
        v.push_back(numbers[n-1-i]);
    }
    while(true){
        int count = v.size();
        // for(auto i : v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        apply(v);
        
        if(v.size() == count) break;
    }
    cout<<v.size()<<endl;
    for(int i=v.size()-1;i>=0; i--){
        cout<<v[i]<<endl;
    }



    // Please write your code here.

    return 0;
}
