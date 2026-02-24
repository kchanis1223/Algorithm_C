#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

int N, G;
int group[25000][10000];
int group_size[25000];

int main() {
    cin >> N >> G;

    vector<set<int>> groups = vector<set<int>>(G,set<int>()); map<int,vector<int>> m; 
    // m[i] = i가 포함되어 있는 전체 그룹 
    for (int i = 0; i < G; i++) { cin >> group_size[i]; for (int j = 0; j < group_size[i]; j++) { cin >> group[i][j]; groups[i].insert(group[i][j]); m[group[i][j]].push_back(i); } } queue<int> q; vector<int> v; q.push(1); while(!q.empty()){ int num = q.front(); v.push_back(num); q.pop(); for(auto g : m[num]){ groups[g].erase(num); if(groups[g].size() == 1) q.push(*groups[g].begin()); } } cout<<v.size();

    return 0;
}
