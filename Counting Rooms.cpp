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
char grid[N][N];
int n, m;
bool check(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.');
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    function<void(int, int)> dfs = [&](int i, int j) {
        grid[i][j] = '#';
        for (int k = 0; k < 4; k++) {
            int xi = i + dx[k];
            int xj = j + dy[k];
            if (check(xi, xj)) {
                dfs(xi, xj);
            }
        }
    };
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
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
