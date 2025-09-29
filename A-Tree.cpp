//------------------------------<<<<Ouda>>>>-----------------------------
#include <bits/stdc++.h>
#define all(n) n.begin(), n.end()
#define ll long long
#define int long long
#define endl "\n"
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char id[] = {'D', 'U', 'R', 'L'};
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7, M = 1e18;
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
    function<bool(int, int)> dfs = [&](int u, int p)-> bool {
        vis[u] = true;
        for (int v: a[u]) {
            if (!vis[v]) {
                if (dfs(v, u))return true;
            } else if (p != v)return true;
        }
        return false;
    };
    int x = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            x |= dfs(i, -1);
        }
    }
    if (!x && n == m + 1)cout << "YES" << endl;
    else cout << "NO" << endl;
}

//===================================
signed main() {
    // ios_base::sync_with_stdio(NULL), cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
