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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char> > g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    function<bool(int, int)> check = [&](int i, int j)-> bool {
        return (i >= n || i < 0 || j >= m || j < 0 || vis[i][j] || g[i][j] == '#');
    };
    function<void(int,int)> dfs = [&](int i,int j) {
        vis[i][j] = true;
        for (int l = 0; l < 4; l++) {
            int xi = i + dx[l];
            int xj = j + dy[l];
            if (!check(xi, xj))dfs(xi, xj);
        }
        if (k) {
            g[i][j] = 'X';
            k--;
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!check(i, j)) {
                dfs(i, j);
            }
            cout << g[i][j];
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
