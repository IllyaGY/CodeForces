#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    while (t--)
    {
        ll size; cin >> size;
        ll odds = size%2 ? size*size : size*size-1;
        ll mx_odd = odds;
        ll mx_even = size%2 ? mx_odd-1 : mx_odd + 1;
        bool stop = 1;
        for (ll i = 2; i <= size; i+=2, odds-=2)
        {
            if (abs(i - odds) == 1)
            {
                cout << -1 << "\n";
                stop = 0;
                break;
            }
        }
        if (!stop) continue;
        ll j = 1;
        for (ll i = 1; i <= mx_odd; j++, i+=2)
        {
            cout << i << " ";
            if (j % size == 0) cout << "\n";
        }
        for (ll i = 2; i <= mx_even; j++, i+=2)
        {
            cout << i << " ";
            if (j % size == 0) cout << "\n";
        }

    }
    return 0;
}
