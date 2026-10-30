#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    vector<string> words;
    vector<int> in_degree(n,0);
    for (int i = 0; i < n; i++) {
        string u;
        cin >> u;
        words.emplace_back(u);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int dif = 0;
            for (int k = 0; k < m; k++) {
                if (words[i][k] != words[j][k]) {
                    dif++;
                }
            }
            if (dif == 1) {
                res++;
                in_degree[i]++;
            }
        }
    }

    int oscuro = 0;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            oscuro++;
        }
    }

    int best = max_element(in_degree.begin(), in_degree.end()) - in_degree.begin();
    cout << (res/2) << " " << in_degree[best] << " " << oscuro << '\n';
    return 0;
}