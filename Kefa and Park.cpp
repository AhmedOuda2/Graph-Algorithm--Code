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
    int n, m;
    cin >> n >> m;
    vector<int> cat(n + 1), a[n + 1];
    for (int i = 1; i <= n; i++) { cin >> cat[i]; }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bool vis[n + 1] = {};
    int ans = 0;
    function<void(int,int)> dfs = [&](int u,int c) {
        vis[u] = true;
        bool ok = true;
        if (c > m)return;
        for (int v: a[u]) {
            if (!vis[v]) {
                ok = false;
                dfs(v, cat[v] ? c + 1 : 0);
            }
        }
        if (ok) ans++;
    };
    dfs(1, cat[1]);
    cout << ans << endl;
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
