#include<bits/stdc++.h>
using namespace std;

const int N = 200000 +5;
int n;
int t;
int k[N];
int L[N];
int R[N];
int altura[N];
int inorder[N];

void calc_height(int x) {
    if (x ==0) altura[x] = -1;
    else {
        calc_height(L[x]);
        calc_height(R[x]);
        altura[x] = max(altura[L[x]], altura[R[x]]);
    }
}

void calc_inorder(int x) {
    if (x == 0) return;
    calc_inorder(L[x]);
    inorder[t++] = k[x];
    calc_inorder(R[x]);
}

int main() {

}