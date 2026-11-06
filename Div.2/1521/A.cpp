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
        ll a, b; cin >> a >> b;
        if (b * a > 2 * a)
        {
            cout << "YES" << endl;
            cout << a << " " << a*b - a << " " << a * b << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << a << " " << a*b << " " << a*b + a << endl;
        }
    }

    return 0;
}


