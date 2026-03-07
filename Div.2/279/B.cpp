#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t;
    cin >> n >> t;
    ll tmp = n;
    vector<ll> v;
    while (tmp--) {
        ll val;
        cin >> val;
        v.push_back(val);
    }
    ll i, j;
    i = 0, j = 0;
    ll tm = 0;
    ll best = 0;
    ll ctr = 0;
    while (j < v.size()) {
        if (tm + v[j] <= t) {
            tm += v[j];
            j++;
            ctr++;
            best = max(ctr, best);
        }
        else {
            tm-=v[i];
            i++;
            ctr--;
        }
    }
    cout << best;
    return 0;
}

