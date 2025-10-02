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
    vector<int> a[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bool vis[n + 1] = {};
    int cnt = 0;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v: a[u]) {
            if (!vis[v]) {
                cnt++;
                dfs(v);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    cout << (1LL << cnt) << endl;
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
