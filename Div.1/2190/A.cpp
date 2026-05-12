#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    ll t; cin >> t;


    while (t--)
    {
        ll val; cin >> val;
        string bits; cin >> bits;
        ll zeros = 0;
        for (auto &i : bits)
        {
            zeros += i == '0' ? 1 : 0;
        }
        ll ones = val - zeros;
        vector<ll> v;
        ll i = 0;
        while (i < bits.size() && zeros--)
        {
            if (bits[i] == '1') v.emplace_back(i+1);
            i++;
        }while (i < bits.size() && ones--)
        {
            if (bits[i] == '0') v.emplace_back(i+1);
            i++;
        }

        if (v.size() == 0) cout << "Bob\n";
        else
        {
            cout << "Alice\n" <<  v.size() << "\n";
            for (auto &num : v) cout << num << " ";
            cout << "\n";

        }



    }
    return 0;
}
