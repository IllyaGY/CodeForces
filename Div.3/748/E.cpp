#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n , k;
        cin >> n >> k;
        vector<ll> v(n + 1, 0);
        vector<vector<ll>> mp(n + 1);
        ll qe = n-1;
        while(qe--){
            ll f, s;
            cin >> f >> s;
            mp[f].emplace_back(s);
            mp[s].emplace_back(f);
            v[f]++;
            v[s]++;
        }
        queue<ll> q;
        for (int i = 1; i < v.size(); i++) if(mp[i].size() <= 1) q.push(i);
        ll s = q.size();
        while(!q.empty() && k){
            ll tp = q.front();
            q.pop();
            for (auto &i : mp[tp]) {
                if (!v[i]) continue;
                v[i]--;
                v[tp]--;
                if (v[i]== 1) q.push(i);
            }
            n--;
            s--;
            if (!s) {
                k--;
                s = q.size();
            }
        }
        cout << n << "\n";
    }
    return 0;
}
