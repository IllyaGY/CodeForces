#include <iostream>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;
    ll val = 16;
    ll arr[] = {2,3,5,7};

    while (t--)
    {
        ll l, r; cin >> l >> r;
        ll ans = r - (l-1);
        for (ll i = 1; i < val; i++)
        {
            ll set = 0;
            ll prod = 1;
            for (ll j = 0; j < 4; j++)
            {
                if ((i >> j) & 1)
                {
                    set++;
                    prod *= arr[j];
                }
            }
            if (set&1) ans -= (r/prod) - (l-1)/prod;
            else ans += r/prod - (l-1)/prod;
        }






        cout << ans << '\n';

    }


    return 0;
}
