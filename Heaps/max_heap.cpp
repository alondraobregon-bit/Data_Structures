#include<bits/stdc++.h>
using namespace ::std;

template<typename data_type>
struct MaxHeap {
    int _size;
    vector<data_type> a;

    MaxHeap(int _size = 0): _size(_size) {
        a = vector<data_type>();
    }
    MaxHeap(const vector<data_type> a) : a(move(a)), _size(a.size()) {
        build_heap();
    }
    int left(int p) {
        return (p << 1) | 1;
    }
    int right(int u) {
        return (u << 1) + 2;
    }
    int parent(int p) {
        return (p -1) >> 1;
    }

    void sift_down(int p) {
        while (left(p) < _size) {
            int m = p;
            int l = left(p), r = right(p);
            if (a[l] > a[m]) {
                m = l;
            }
            if (r < _size and a[r] > a[m]) {
                m = r;
            }
            if (m == p) break;
            swap(a[p], a[m]);
            p = m;
        }
    }

    void sift_up(int u) {
        while (u>0 and a[parent(u)] < a[u]) {
            swap(a[parent(u)], a[u]);
            u = parent(u);
        }
    }

    void build_heap() {
        for (int i = parent(_size - 1); i >= 0; i--) {
            sift_down(i);
        }
    }
    data_type top() const {
        return a[0];
    }
    void pop() {
        swap(a[0], a[_size -1]);
        a.pop_back();
        --_size;
        sift_down(0);
    }
    data_type extract_max() {
        data_type max_val = a[0];
        pop();
        return max_val;
    }
    void insert(data_type value) {
        a.emplace_back(value);
        ++_size;
        sift_up(_size -1);
    }
    int size() const {
        return _size;
    }
    bool empty() const {
        return _size == 0;
    }
};