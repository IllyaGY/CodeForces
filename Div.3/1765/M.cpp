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
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
//if divisble by 3 == 2/3 * val
// if divible by 5 and not even == 1/5 * val
// if divible by 7 and not even == 1/7 * val
// if prime == 1 and p - 1

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    ll t; cin >> t;

    while (t--)
    {
        ll val; cin >> val;
        //Biggest divisor is the best solution
        if (val % 2 == 0)
        {
            cout << val / 2 << " " << val / 2 << "\n";
            continue;
        }
        ll div = 3;
        for (; div * div <= val; div +=2)
        {
            if (val % div == 0)
            {
                cout << val / div << " " << val - val/div << "\n";
                div = 0;
                break;
            }
        }
        if (div * div > val) cout << 1 << " " << val - 1 << "\n";

    }


    return 0;
}


// 15
// 7 8