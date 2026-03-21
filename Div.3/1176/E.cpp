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

    ll t;
    cin >> t;
    while (t--) {
        ll n , m;
        cin >> n >> m;
        vector<ll> vec (n + 1, -1);
        vector<vector<ll>> v;
        ll q = m;
        while(q--){
            ll f, s;
            cin >> f >> s;
            if (vec[f]==-1) {
                v.push_back({});
                vec[f] = (ll) (v.size()-1);
            }
            if (vec[s]==-1) {
                v.push_back({});
                vec[s] = (ll) (v.size()-1);

            }
            v[vec[f]].push_back(s);
            v[vec[s]].push_back(f);
        }
        ll even = 1, odd = 0;
        vector<ll> seen(n + 1,-1);
        queue<ll> qe;
        qe.push(1);
        seen[1] = 0;
        ll sz = 1;
        while (!qe.empty()) {
            auto t = qe.front();
            qe.pop();
            sz--;
            for (auto &i : v[vec[t]]) {
                if (seen[i] == -1) {
                    qe.push(i);
                    seen[i] = seen[t] ^ 1;
                    if (seen[i]) odd++;
                    else even++;
                }
            }


        }
        bool par = 0;
        if ((even > odd) && (odd)) par = 1;
        cout << min((even ? even : LLONG_MAX), (odd ? odd : LLONG_MAX)) << "\n";
        for (int i = 1; i <= n; i++) {
            if (seen[i] % 2 == par) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
