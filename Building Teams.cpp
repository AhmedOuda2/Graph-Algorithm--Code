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
    vector<int> a[n + 1] = {};
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> ans(n + 1, -1);
    bool ok = false;
    function<void(int,int)> dfs = [&](int u,int x) {
        ans[u] = x;
        for (int v: a[u]) {
            if (ans[v] == -1) {
                dfs(v, x == 1 ? 2 : 1);
            } else if (ans[v] == ans[u]) {
                ok = true;
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (ans[i] == -1) {
            dfs(i, 1);
        }
    }
    if (ok) cout << "IMPOSSIBLE" << endl;
    else for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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
