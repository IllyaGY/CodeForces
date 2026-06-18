#include <iostream>
#include <string>
#include <vector>

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

//n != 1
//none of the digits can be 0
// 1 cannot be in there !!!


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        if (n < 2)
        {
            cout << -1 << endl;
            continue;
        }
        cout << "2";
        for (int i = 1; i < n; i++)
        {
            cout << "3";
        }
        cout << endl;

    }
// 1 2 3 4 5 6 7 8 9
// endings 3 7 9
// min digit = 2
    // min ending = 3

//    2 3 3 3 all three and one 2 not at the end

    return 0;
}


