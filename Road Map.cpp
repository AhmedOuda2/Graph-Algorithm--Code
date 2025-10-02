//------------------------------<<<<Ouda>>>>-----------------------------
#include <bits/stdc++.h>
#define all(n) n.begin(), n.end()
#define ll long long
#define int long long
#define endl "\n"
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int N = 1e3 + 5, mod = 1e9 + 7, M = 1e18;
//===================================
void solve() {
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    vector<int> a[n + 1];
    for (int i = 1; i <= n; i++) {
        if (i == r1)continue;
        int u;
        cin >> u;
        a[u].push_back(i);
        a[i].push_back(u);
    }
    bool vis[n + 1] = {};
    vector<int> ans(n + 1);
    function<void(int,int)> dfs = [&](int u,int p) {
        vis[u] = true;
        ans[u] = p;
        for (int v: a[u]) {
            if (!vis[v]) {
                dfs(v, u);
            }
        }
    };
    dfs(r2, -1);
    for (int i = 1; i <= n; i++) {
        if (i == r2)continue;
        cout << ans[i] << " ";
    }
}

//===================================
signed main() {
    ios_base::sync_with_stdio(NULL), cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
