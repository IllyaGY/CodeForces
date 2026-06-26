#include <iostream>
#include <string>
#include <cmath>

typedef long long ll;

using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b, ll g = 0)
{
    if (g) return (a / g) * b;
    return (a / gcd(a, b)) * b;  // a * b / gcd
}

bool sieve[100000001];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i * i < 100000001; i++)
    {
        if (sieve[i]) continue;
        ll temp = i * i;
        while (temp < 100000001)
        {
            sieve[temp] = 1;
            temp += i;
        }
    }


    ll t; cin >> t;

back:   while (t--)
        {

            ll c; cin >> c;
            ll g = 0;
            while (c--)
            {
                ll val; cin >> val;
                if (g) g = gcd(g, val);
                else g = val;
            }
            for (int i = 2; i < 100000001; i++)
            {
                if (sieve[i]) continue;
                if (gcd(g, i) == 1)
                {
                    cout << i << endl;
                    break;
                }
            }

        }


    return 0;
}

