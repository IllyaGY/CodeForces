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
        ll zeros = 0; ll ones = 0;
        for (int i = 0; i < val; i++)
        {
            ll tmp; cin >> tmp; if (!tmp) zeros++; else if (tmp == 1) ones++;
        }
        if (zeros == 1 || (zeros >= 2 && ones >= 1)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
