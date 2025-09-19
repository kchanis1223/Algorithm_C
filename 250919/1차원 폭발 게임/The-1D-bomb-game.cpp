#include <iostream>
#include <vector>

using namespace std;

int n, m;
int numbers[100];

void apply(vector<int> &v){
    vector<int> result;
    for(int i=0;i<v.size();){
        vector<int> tmp;
        tmp.push_back(v[i]);
        for(int j = i+1;j<v.size();j++){
            if(v[j] == tmp[0]){
                tmp.push_back(v[j]);
            }
            else break;
        }
        i += tmp.size();
        //cout<<"tmp.size() : "<<tmp.size()<<endl;
        if(tmp.size() < m){
            for(auto j : tmp){
                result.push_back(j);
            }
        }
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
        // cout<<"before"<<endl;
        // for(auto i : v){
        //     cout<<i<<" ";
        // }
        //cout<<endl;
        apply(v);
        //cout<<"after"<<endl;
        // for(auto i : v){
        //     cout<<i<<" ";
        // }
        //cout<<endl;
        if(v.size() == count || v.size() < m) break;
    }
    cout<<v.size()<<endl;
    for(int i=v.size()-1;i>=0; i--){
        cout<<v[i]<<endl;
    }



    // Please write your code here.

    return 0;
}
