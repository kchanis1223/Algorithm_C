#include <iostream>
#include <string>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

string inp[3];

int main() {
    for (int i = 0; i < 3; i++) cin >> inp[i];

    // Please write your code here.
    set<char> s;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            s.insert(inp[i][j]);
        }
    }
    // 숫자 2개를 선택하고 8가지 상황에 대해 체크
    vector<int> v;
    for(auto &c1 : s){
        v.push_back(c1);
    }
    int count = 0;
    set<pair<int,int>> result;
    for(int i=0;i<v.size()-1;i++){
        char c1 = v[i];
        for(int j=i+1;j<v.size();j++){
            char c2 = v[j];
            vector<vector<pair<int,int>>> lines = { {{0,0},{1,0},{2,0}} , {{0,1},{1,1},{2,1}} , 
            {{0,2},{1,2},{2,2}} , {{0,0},{0,1},{0,2}} , {{1,0},{1,1},{1,2}} , 
            {{2,0},{2,1},{2,2}} , {{0,0},{1,1},{2,2}} , {{2,0},{1,1},{0,2}} };
            bool isValid = false;
            for(auto& line : lines){
                bool isOk = true;
                for(auto& p :line){
                    int x = p.first;
                    int y = p.second;
                    if(inp[x][y] != c1 && inp[x][y] != c2){
                        isOk = false;
                        break;
                    }
                }
                if(inp[line[0].first][line[0].second] == inp[line[1].first][line[1].second]
                && inp[line[0].first][line[0].second] == inp[line[2].first][line[2].second] ) continue;
                if(isOk){
                    isValid = true;
                    //cout<<"c1,c2 ="<<c1<<","<<c2<<endl;
                    break;
                }
            }
            if(isValid){
                result.insert({c1,c2});
            }
        }
    }
    cout<<result.size();
    return 0;
}