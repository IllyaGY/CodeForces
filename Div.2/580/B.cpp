#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, d;
    cin >> n >> d;
    ll tmp = n;
    vector<pair <ll, ll>> v;
    while (tmp--) {
        pair <ll, ll> val;
        cin >> val.first >> val.second;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    ll i, j;
    i = 0, j = 0;
    ll cur = 0;
    ll best = 0;
    ll min_m = v[0].first;
    while (j < v.size()) {
        if (v[j].first - min_m < d) {
            cur += v[j].second;
            best = max(cur, best);
            j++;

        }
        else {
            cur-=v[i].second;
            i++;
            min_m = v[i].first;

        }
    }
    cout << best;
    return 0;
}
