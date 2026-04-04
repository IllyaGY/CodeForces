#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n;
    cin >> n;
    vector<ll> cost(n+1);
    vector<vector<ll>> v (n + 1, {0,0});

    //0 - not rotated
    //1 - rotated
    for (ll i = 1; i <= n; i++) cin >> cost[i];
    v[1][1] += cost[1];
    string tmp; cin >> tmp; string tmp_rev = tmp ; reverse(tmp_rev.begin(), tmp_rev.end());
    for (ll i = 2; i <= n; i++)
    {
        v[i] = {LLONG_MAX, LLONG_MAX};
        string s; cin >> s; string r = s; reverse(r.begin(), r.end());


        if (s >= tmp) //Current same, prev same
        {
            v[i][0] = min(v[i][0] , v[i-1][0]);
        }
        if (s >= tmp_rev) v[i][0] = min(v[i][0 ],v[i-1][1]); //Prev reversed, cur same

        if (r >= tmp) //Current reversed, prev same
        {
            v[i][1] = min(v[i][1], v[i-1][0]);
        }
        if (r >= tmp_rev) //Current reversed, prev reversed
        {
            v[i][1] = min(v[i][1], v[i-1][1]);
        }
        v[i][1] += v[i][1] < LLONG_MAX ? cost[i] : 0;
        tmp = s;
        tmp_rev = r; 
    }


    ll ret = min(v[n][0], v[n][1]);
    ret = (ret < LLONG_MAX) ? ret : -1;
    cout << ret;
    return 0;
}
