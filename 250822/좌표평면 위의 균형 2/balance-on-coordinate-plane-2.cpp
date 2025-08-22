#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int X[100], Y[100];

int main() {
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        v.push_back({X[i],Y[i]});
    }

    int result = 100;
    for(int i=2;i<=100;i+=2){
        int minCount = 100;

        int xAxis = i;
        for(int j=2;j<=100;j+=2){
            vector<int> tmp(4,0);
            int yAxis = j;
            for(auto &[x,y] : v){
                if(x<xAxis && y<yAxis) tmp[0] +=1;
                if(x<xAxis && y>yAxis) tmp[1] +=1;
                if(x>xAxis && y<yAxis) tmp[2] +=1;
                if(x>xAxis && y>yAxis) tmp[3] +=1;
            }
            int maxN = *max_element(tmp.begin(),tmp.end());
            if(minCount > maxN) minCount = maxN;
        }
        if(result > minCount)result = minCount;
    }
    cout<<result;
    // Please write your code here.

    return 0;
}