#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tests; cin >> tests;
    while (tests--)
    {
        ll t; cin >> t;
        vector<ll> a(t);
        for (int i=0; i<t; i++) cin >> a[i];
        vector<bool> b(t + 1, 1);

        ll k = 1;
        vector<pair<ll, ll>> c(t);
        for (auto &i : a)
        {
            c.emplace_back(i * k, (i+1) * k-1);
        }
        sort(c.begin(), c.end());
        vector<pair<ll, ll>> inv;
        ll mn = c[0].first;
        ll mx = LLONG_MIN;
        for (int i = 0; i < c.size(); i++)
        {
            if (mx < c[i].first && mx > LLONG_MIN)
                inv.emplace_back(mn, mx);
            mx = max(mx, c[i].second);

        }

        ll ctr = t;
        for (auto & i : inv)
        {
            for (ll j = i.first; j < i.second && j < t; j++)
            {
                if (!b[j]) continue;
                ctr--;
                b[j] = 0;
            }
        }
        cout << ctr << endl;
        for (ll j = 0; j < t; j++)
        {
            if (!b[j]) continue;
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

//0 - 0 doesnt exist k = 1
//3 - 2 exists, 4,5 k = 2
//2 - 3 exists, k = 3
//2 - 4 exists ,k = 4
//2 - 5 exists, k = 5
//1 - k = 6

//Not Present
//0 - 0 is not present, k = 1
//3 - 6, 7, 8 dont exist, k = 2
//2 - 6, 7 ,8 dont exist, k = 3
//2 - 8, 9, 10, 11, k = 4
//2 - 10, 11, 12... 14, k = 5
//1 - 6, 7, 8, 9, .. 11, k = 6
