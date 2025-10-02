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
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)return;
        vector<int> a[n + 1];
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
        }
        bool vis[n + 1] = {};
        vector<int> ans;
        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            for (int v: a[u]) {
                if (!vis[v]) {
                    dfs(v);
                }
            }
            ans.push_back(u);
        };
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        for (int i = n - 1; ~i; i--) {
            cout << ans[i] << " ";
        }
        cout << endl;
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
