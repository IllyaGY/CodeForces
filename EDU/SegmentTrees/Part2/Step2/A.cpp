#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
ll tree[4 * N];
int pos_arr[N];

void build(int l, int r, int pos) {
    if (l == r) {
        pos_arr[r] = pos;
        return;
    }

    int middle = (l + r) / 2;
    build(l, middle, pos * 2);
    build(middle + 1, r, pos * 2 + 1);
}

void update(int l, int r, int tl, int tr, int pos, int x) {
    if (l == tl && r == tr) {
        tree[pos] += x;
        return;
    }

    int middle = (tl + tr) / 2;
    if (r <= middle) {
        update(l, r, tl, middle, pos * 2, x);
        return;
    }

    if (l > middle)
    {
        update(l, r, middle + 1, tr, pos * 2 + 1, x);
        return;
    }

    update(l, middle, tl, middle, pos * 2, x);
    update(middle + 1, r, middle + 1, tr, pos * 2 + 1, x);
}

ll query(int ind) {
    int pos = pos_arr[ind];
    ll res = 0;
    while (pos > 0) {
        res += tree[pos];
        pos /= 2;
    }

    return res;
}

int main() {
    int n, q;
    cin >> n >> q;
    short op;
    int l, r, ind;
    ll x;
    build(0, n - 1, 1);

    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> x;
            update(l, r - 1, 0, n - 1, 1, x);
        }
        else {
            cin >> ind;
            cout << query(ind) << endl;
        }
    }
}