#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm_ll(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        vector<ll> b(n);
        for (ll &x : a) cin >> x;
        for (ll &x : b) cin >> x;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ll need = a[i];

            ll left = -1, right = -1;
            if (i)
                left = gcd(a[i - 1], a[i]);
            if (i + 1 < n)
                right = gcd(a[i], a[i + 1]);

            if (left != -1 && right != -1) need = lcm_ll(left, right);
            else if (left != -1) need = left;
            else if (right != -1) need = right;

            if (need < a[i]) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}