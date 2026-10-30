#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // Lectura
    int w;
    string s, t;
    cin >> w >> s >> t;

    int k;
    cin >> k;
    unordered_set<string> prohibido;
    for (int i = 0; i < k; i++) {
        string p;
        cin >> p;
        prohibido.insert(p);
    }

    // Si el inicio o el objetivo están prohibidos, es imposible
    if (prohibido.count(s) || prohibido.count(t)) {
        cout << -1 << '\n';
        return 0;
    }

    // BFS
    unordered_map<string, int> dist;  // si un código no está aquí, no se visitó
    queue<string> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        string x = q.front();
        q.pop();

        if (x == t) {
            cout << dist[x] << '\n';
            return 0;
        }

        // Generar los vecinos: cada rueda, hacia arriba y hacia abajo
        for (int i = 0; i < w; i++) {
            for (int d : {1, -1}) {
                string y = x;
                int digito = x[i] - '0';
                int nuevo = (digito + d + 10) % 10;
                y[i] = '0' + nuevo;

                if (!prohibido.count(y) && !dist.count(y)) {
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
        }
    }

    // La cola se vació sin llegar a t
    cout << -1 << '\n';
    return 0;
}