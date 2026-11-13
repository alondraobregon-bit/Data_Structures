#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;
const int MAXN = 200000 + 5;

int n, m;
vector<pair<int, ll>> G[MAXN];     // Grafo original: u -> (v, w)
vector<pair<int, ll>> G_rev[MAXN]; // Grafo invertido: v -> (u, w)

vector<ll> dijkstra(int start, vector<pair<int, ll>> adj[]) {
    vector<ll> dist(n + 1, INF);
    // Min-heap: {distancia_acumulada, nodo}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        // Si ya encontramos un camino mejor antes, ignoramos esta entrada vieja
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G_rev[v].push_back({u, w}); // Arista invertida para el regreso
    }
    
    vector<ll> dist_ida = dijkstra(1, G);
    vector<ll> dist_vuelta = dijkstra(1, G_rev);
    
    int atendidas = 0;
    ll tiempo_total = 0;
    
    for (int v = 1; v <= n; ++v) {
        if (dist_ida[v] != INF && dist_vuelta[v] != INF) {
            atendidas++;
            tiempo_total += dist_ida[v] + dist_vuelta[v];
        }
    }
    
    cout << atendidas << ' ' << tiempo_total << '\n';
    
    return 0;
}