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
    int c = 0;
    vector<vector<char> > g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'G') c++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'B') {
                if (i > 0 && g[i - 1][j] != 'B')g[i - 1][j] = '#';
                if (i < n - 1 && g[i + 1][j] != 'B')g[i + 1][j] = '#';
                if (j < m - 1 && g[i][j + 1] != 'B')g[i][j + 1] = '#';
                if (j > 0 && g[i][j - 1] != 'B')g[i][j - 1] = '#';
            }
        }
    }
    int cnt = 0;
    function<bool(int, int)> check = [&](int i, int j)-> bool {
        return (i >= n || i < 0 || j >= m || j < 0 || g[i][j] == '#');
    };
    function<void(int,int)> dfs = [&](int i,int j) {
        if (g[i][j] == 'G')cnt++;
        g[i][j] = '#';
        for (int l = 0; l < 4; l++) {
            int xi = i + dx[l];
            int xj = j + dy[l];
            if (!check(xi, xj))dfs(xi, xj);
        }
    };
    if (!check(n - 1, m - 1)) {
        dfs(n - 1, m - 1);
    }
    if (cnt == c)cout << "YES" << endl;
    else cout << "NO" << endl;
}

//===================================
signed main() {
    ios_base::sync_with_stdio(NULL), cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
