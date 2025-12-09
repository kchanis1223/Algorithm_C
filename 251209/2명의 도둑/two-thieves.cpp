#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int weightArr[10][10];

int bestSubsetProfit(const vector<int>& v) {
    int best = 0;

    function<void(int,int,int)> dfs = [&](int idx, int sum, int profit) {
        if (sum > c) return;
        best = max(best, profit);
        if (idx == (int)v.size()) return;

        // 안 고름
        dfs(idx + 1, sum, profit);
        // 고름
        dfs(idx + 1, sum + v[idx], profit + v[idx] * v[idx]);
    };

    dfs(0, 0, 0);
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> weightArr[i][j];
    }

    // 각 (i, j) = i행에서 j~j+m-1 구간을 잡았을 때, 그 구간에서 얻을 수 있는 최대 이익(제곱합)
    vector<vector<int>> profit(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - m; j++) {
            vector<int> seg;
            seg.reserve(m);
            for (int k = 0; k < m; k++) seg.push_back(weightArr[i][j + k]);
            profit[i][j] = bestSubsetProfit(seg);
        }
    }

    int ans = 0;

    // 첫 번째 도둑 구간 (r1, c1)
    for (int r1 = 0; r1 < n; r1++) {
        for (int c1 = 0; c1 <= n - m; c1++) {
            int p1 = profit[r1][c1];

            // 두 번째 도둑 구간 (r2, c2)
            for (int r2 = 0; r2 < n; r2++) {
                for (int c2 = 0; c2 <= n - m; c2++) {
                    // 같은 행이면 구간이 겹치면 안 됨
                    if (r1 == r2) {
                        int l1 = c1, r1end = c1 + m - 1;
                        int l2 = c2, r2end = c2 + m - 1;
                        bool overlap = !(r1end < l2 || r2end < l1);
                        if (overlap) continue;
                    }

                    int p2 = profit[r2][c2];
                    ans = max(ans, p1 + p2);
                }
            }
        }
    }

    cout << ans;
    return 0;
}
