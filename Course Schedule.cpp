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
    vector<int> a[n + 1], ans;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    int vis[n + 1] = {};
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (int v: a[u]) {
            if (!vis[v]) {
                dfs(v);
            } else if (vis[v] == 1)vis[0] = true;
        }
        vis[u] = 2;
        ans.push_back(u);
    };
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
        if (vis[0]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for (int i = n - 1; ~i; i--) {
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
