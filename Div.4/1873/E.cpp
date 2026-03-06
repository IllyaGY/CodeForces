#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll aqr(vector<ll>& nums, ll x) {
    ll mn = LLONG_MAX;
    ll mx = -1;
    for (auto &i : nums) {mx = max(mx, i); mn = min(i, mn);}
    mx += x/ll(nums.size());
    ll best = mn;
    while (mn <= mx) {
        ll mid = (mx + mn) / 2;
        ll w = x;
        bool s = 1;
        for (auto &i : nums) {
            ll diff = mid - i;
            if (diff <= 0) continue;
            w-=diff;
            if (w < 0) {
                s = 0;
                break;
            }
        }
        if (!s) mx = mid - 1;
        else {
            best = mid;
            mn = mid + 1;
        }
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 0;
    cin >> t;
    while (t--) {
        ll v, x;
        cin >> v >> x;
        vector<ll> n = {};
        while (v--) {
            ll t = 0;
            cin >> t;
            n.push_back(t);
        }
        cout << aqr(n, x) << "\n";
    }
    return 0;

}
