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


    ll n;
    cin >> n;
    vector<ll> ct (100002);
    vector<ll> v (100002); //taken -- sum
    ll sum = 0;
    ll start = LLONG_MAX;
    ll end = -1;
    for (ll i = 1; i <= n; i++)
    {
        ll tmp; cin >> tmp;
        ct[tmp]++;
        sum+=tmp;
        start = min(start,tmp);
        end = max(end, tmp);
    }
    vector<ll> gain(100001);
    ll mx = 0;
    for (ll i = start; i <= end; i++)
    {
        gain[i] += max(ct[i] * i + (i>=2 ? gain[i-2] : 0), gain[i-1]);

    }


    cout << gain[end];
    return 0;
}
