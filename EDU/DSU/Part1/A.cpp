#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e5 + 1;

ll arr[N] = {0};

void init()
{
    for (ll i = 1; i < N; ++i) arr[i] = i;
}


ll get(ll a)
{
    if (a == arr[a]) return a;

    arr[a] = get(arr[a]);

    return arr[a];
}




void u(ll c1, ll c2){
    ll l1 = get(c1);
    ll l2 = get(c2);

    if (l1 == l2) return;

    arr[l2] = l1;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    init();

    while (m--) {
        string s;
        int l, r;
        cin >> s >> l >> r;
        if (s == "union") u(l, r);
        else
        {
            if (get(l) == get(r)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}