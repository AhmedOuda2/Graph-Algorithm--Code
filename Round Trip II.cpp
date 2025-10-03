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
    }
    vector<int> ans(n + 1, -1);
    int vis[n + 1] = {};
    int x = 0, y = 0;
    function<void(int,int)> dfs = [&](int u,int p) {
        vis[u] = 1;
        ans[u] = p;
        for (int v: a[u]) {
            if (!vis[v]) {
                dfs(v, u);
            } else if (vis[v] == 1 && !x)x = u, y = v;
        }
        vis[u] = 2;
    };
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
        if (x)break;
    }
    if (!x) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> b = {y};
    while (x != y) {
        b.push_back(x);
        x = ans[x];
    }
    b.push_back(y);
    cout << b.size() << endl;
    reverse(all(b));
    for (auto u: b)cout << u << " ";
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
