#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;

int n, t;
vector<int> G[MAXN];
vector<int> path;

// u: nodo actual, p: nodo padre (jefe directo, para no volver hacia arriba)
bool dfs(int u, int p) {
    path.push_back(u);
    
    // Si llegamos al empleado objetivo t, terminamos con éxito
    if (u == t) {
        return true;
    }
    
    for (int v : G[u]) {
        if (v == p) continue; // Evitar regresar al jefe
        if (dfs(v, u)) {
            return true; // Propagar el éxito hacia arriba sin hacer pop_back
        }
    }
    
    // Si este camino no llevó a t, retrocedemos
    path.pop_back();
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> t;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1, 0); // Iniciamos desde el director (1), con padre ficticio 0
    
    // Imprimir cantidad k de empleados en el camino
    cout << path.size() << '\n';
    // Imprimir los k empleados en orden desde el director hasta t
    for (int i = 0; i < (int)path.size(); ++i) {
        cout << path[i] << (i + 1 == (int)path.size() ? '\n' : ' ');
    }
    
    return 0;
}