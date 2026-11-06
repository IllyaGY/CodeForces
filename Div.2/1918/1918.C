#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll t; cin >> t;
    while(t--)
    {
        ll a,b,r;
        cin >> a >> b >> r;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        ll mx = max(a, b);
        ll mn = min(a, b);
        ll x = 0;
        ll bit = 60; // Should fit into LL
        while ((a & (1LL << bit)) == (b & (1LL << bit)))
            bit--;
        bit--;
        while (bit >= 0)
        {
            if ((mx & (1LL << bit)) != (mn & (1LL << bit)) &&
                ((mn & (1LL << bit)) == 0))
                x = x | (1LL << bit);
            if (x > r)
                x = x ^ (1LL << bit);
            bit--;
        }
        cout << abs((a ^ x) - (b ^ x)) << endl;
    }

    return 0;
}