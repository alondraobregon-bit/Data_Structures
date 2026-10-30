#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> edge_hashes(n+1, vector<bool>(n+1, false));
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        edge_hashes[u][v] = edge_hashes[v][u] = true;
    }
    int res = 0;
    for (auto &e : edges) {
        int u, v;
        tie(u, v) = e;
        for (int i = 1; i <= n; i++) {
            if (edge_hashes[u][i] && edge_hashes[v][i]){
                ++res;
            }
        }
    }
    cout << (res/3) << '\n';
    return 0;
}