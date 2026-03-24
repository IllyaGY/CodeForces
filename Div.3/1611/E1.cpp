#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll tests; cin >> tests;
    while (tests --) {
        ll n, k;
        cin >> n >> k;
        vector<ll> fr;
        for (ll i = 1; i <= k; i++) {
            ll fri; cin >> fri;
            fr.emplace_back(fri);
        }
        ll tm = n-1;
        vector<vector<ll>> v(n+1);
        while(tm--){
            ll f, s;
            cin >> f >> s;
            v[f].emplace_back(s);
            v[s].emplace_back(f);
        }

        queue<ll> q;

        vector<bool> seen(n + 1, 0);
        vector<bool> fseen(n + 1, 0);



        q.push(1);
        seen[1] = 1;
        vector<ll> distK (n + 1, 0);
        vector<ll> distF (n + 1, 0);
        vector<ll> leaves;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            ll leaf = 1;
            for (auto & i: v[t]) {
                if (seen[i])continue;
                leaf = 0;
                q.push(i);
                seen[i]=1;
                distK[i] = distK[t] + 1;
            }
            if (leaf) leaves.emplace_back(t);
        }
        for (auto &i : fr) {fseen[i] = 1; q.push(i); }
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            for (auto & i: v[t]) {
                if (fseen[i]) continue;
                q.push(i);
                fseen[i]=1;
                distF[i] = distF[t] + 1;
            }
        }
        bool val = 0;
        for (auto & i : leaves) {
            if (distK[i] < distF[i]) {
                cout << "Yes\n";
                val = 1;
                break;
            }
        }
        if (!val) cout << "No\n";
    }
    return 0;
}
