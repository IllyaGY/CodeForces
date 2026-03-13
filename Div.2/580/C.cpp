#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> v1(n+1);
    vector<ll> v(n+1);
    vector<ll> visited (n+1, 0);
    visited[1] = 1;
    queue<ll> q;

    ll k = n;
    while(k--) {cin >> v[n-k]; }
    k = n;
    while (k > 1) {
        ll f, s;
        cin >> f >> s;
        if (min(f,s) == 1) {
            ll mx = max(f,s) ;
            q.push(mx);
            if (v[mx]) v[mx] += v[1];
        }
        k--;
        v1[f].push_back(s); 
        v1[s].push_back(f);

    }
    ll ctr = 0;

    while (!q.empty()) {
        ll val = q.front();
        q.pop();
        visited[val] = 1;
        ll ct = 0;
        for (auto &i : v1[val]) {
            if (visited[i]) continue;
            q.push(i);
            if (v[i] || v[val] > m) v[i] += v[val];
            ct++;
        }
        if (!ct && v[val] <= m) ctr++;
    }

    cout << ctr;
    return 0;
}
