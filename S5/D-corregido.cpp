#include <bits/stdc++.h>
using namespace std;

template<typename key_type, typename value_type>
struct my_map {
    int m;
    vector<vector<pair<key_type, value_type>>> chains;
    my_map(int m) : m(m) {
        chains.resize(m);
    }
    value_type& operator [] (const key_type &key) {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position][at].first != key) {
            ++at;
        }
        if (at == chains[chain_position].size()) {
            chains[chain_position].emplace_back(key, value_type());
        }
        return chains[chain_position][at].second;
    }
    bool has_key (const key_type &key) const {
        int chain_position = _hash(key);
        int at = 0;
        while (at < chains[chain_position].size() and chains[chain_position][at].first != key) {
            ++at;
        }
        return at != chains[chain_position].size();
    }
    int _hash(key_type key) const {
        const int B = 311;
        const int MOD = 1e9 + 7;
        long long hash_value = 0;
        key_type k = key;
        if (k == 0) return 0 % m; // caso especial: while(key>0) nunca entra
        while (k > 0) {
            int d = k % 10;
            hash_value = (hash_value * B + (d + 1)) % MOD;
            k /= 10;
        }
        return (int)(hash_value % m);
    }
    int size() const {
        int result = 0;
        for (int i = 0; i < (int)chains.size(); ++i)
            result += chains[i].size();
        return result;
    }
};

const long long OFFSET = 1e9;

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    long long n, T;
    cin >> n >> T;
    my_map<unsigned int, int> H(2 * n + 1);
    bool found = false;
    for (int i = 0; i < n; ++i) {          // FIX 1: recorrer n, no T
        long long x;
        cin >> x;
        long long complemento = T - x + OFFSET;   // FIX 2 y 3: mismo offset, en long long
        if (H.has_key((unsigned int)complemento)) {
            found = true;
        }
        H[(unsigned int)(x + OFFSET)];
    }
    cout << (found ? "SI" : "NO") << '\n';
    return 0;
}//
