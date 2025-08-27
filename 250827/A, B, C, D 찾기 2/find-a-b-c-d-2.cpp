#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[15];

int main() {
    vector<int> v;
    for (int i = 0; i < 15; i++) {
        cin >> nums[i];
        v.push_back(nums[i]);
    }

    // Please write your code here.
    bool flag = false;
    sort(v.begin(),v.end());
    int total = v[14];
    for(int a=1;a<total;a++){
        for(int b=1;b<total;b++){
            for(int c= 1;c<total;c++){
                for(int d =1;d<total;d++){
                    if(a+b+c+d > total) continue;
                    bool isValid = true;
                    vector<int> r;
                    r.push_back(a); r.push_back(b); r.push_back(c); r.push_back(d);
                    r.push_back(a+b); r.push_back(b+c); r.push_back(c+d); r.push_back(a+d); r.push_back(a+c); r.push_back(b+d); 
                    r.push_back(a+b+c); r.push_back(a+b+d); r.push_back(a+c+d); r.push_back(b+c+d); 
                    r.push_back(a+b+c+d);

                    sort(r.begin(),r.end());
                    for(int i=0;i<r.size();i++){
                        if(r[i] == v[i]) continue;
                        isValid = false;
                        break;
                    }
                    if(isValid) { 
                        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag)break;
        }
        if(flag) break;
    }
    return 0;
}