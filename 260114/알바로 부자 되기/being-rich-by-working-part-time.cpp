#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int s[1000], e[1000], p[1000];

struct Node{
    int start, end, pay;
    Node(int start, int end, int pay) : start(start), end(end), pay(pay) {}
};

bool compare(Node& a , Node& b){
    return a.end < b.end ;
}
int main() {
    cin >> N;

    vector<Node> v;
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
        v.push_back(Node(s[i],e[i],p[i]));
    }

    vector<int> dp = vector<int>(N+1,0); // i번째 알바를 마지막으로 선택했을 때의 최대 돈

    sort(v.begin(),v.end(), compare);
    // for(auto i : v){
    //     cout<<i.start<<","<<i.end<<","<<i.pay<<endl;
    // }
    for(int i=0;i<N;i++){
        dp[i] = v[i].pay;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(v[j].end < v[i].start){
                dp[i] = max(dp[i] , dp[j] + v[i].pay);
            }
        }
    }
    // for(auto i : dp) cout<<i<<" ";
    // cout<<endl;
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}
