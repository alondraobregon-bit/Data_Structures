#include <iostream>
using namespace std;

struct Term {
    long long exp;
    long long coef;
    Term* next;
};

struct PolyList {
    Term* head = nullptr;
    Term* tail = nullptr;
    long long count = 0;

    void append(long long exp, long long coef) {
        Term* newTerm = new Term{exp, coef, nullptr};
        if (head == nullptr) {
            head = tail = newTerm;
        }
        else {
            tail -> next = newTerm;
            tail = newTerm;
        }
        count++;
    }

    void readPoly() {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            long long exp, coef;
            cin >> exp >> coef;
            append(exp, coef);
        }
    }
};

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);

    PolyList P;
    P.readPoly();

    PolyList Q;
    Q.readPoly();

    PolyList R;

    Term* p = P.head;
    Term* q = Q.head;

    while (p != nullptr and q != nullptr) {
        if (p->exp < q->exp) {
            R.append(p->exp, p->coef);
            p = p->next;
        }
        else if (p-> exp > q -> exp) {
            R.append(q->exp, q->coef);
            q = q->next;
        }
        else if (p->exp == q->exp) {
            long long temp = p->coef + q->coef;
            if (temp != 0) {
                R.append(p->exp, temp);
            }
            p = p->next;
            q = q->next;
        }
    }

    while (p != nullptr) {
        R.append(p->exp, p->coef);
        p = p->next;
    }

    while (q != nullptr) {
        R.append(q->exp, q->coef);
        q = q->next;
    }

    cout << R.count << '\n';

    Term* r = R.head;
    while (r != nullptr) {
        cout << r -> exp << ' ' << r -> coef << '\n';
        r = r-> next;
    }
    return 0;
}