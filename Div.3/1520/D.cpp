#include <iostream>
#include <string>
#include <unordered_map>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;

    while (t--)
    {

        ll total = 0;
        ll val; cin >> val;
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < val; i++)
        {
            ll tmp; cin >> tmp;
            if (mp[tmp - i]) total+=mp[tmp-i];
            mp[tmp - i]++; // aj - j == ai - i
        }
        cout << total << endl;


    }
    return 0;
}
