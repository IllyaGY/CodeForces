#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t; cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll tm = n-1;
        vector<ll> v(n+1, 0);
        for (ll i = 2; i <= n; i++) cin >> v[i];
        string s; cin >> s;
        vector<pair<ll, ll>> pref(n+1, {0,0}); //while black
        ll ctr = 0;
        for (ll i = n; i >= 1; i--) {
            if (s[i-1] == 'W') pref[i].first += 1;
            else if (s[i-1] == 'B') pref[i].second += 1;
            pref[v[i]].first += pref[i].first;
            pref[v[i]].second += pref[i].second;
            if (pref[i].second == pref[i].first) ctr++;
        }
        cout << ctr << "\n";
    }
    return 0;
}
