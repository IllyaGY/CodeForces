#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, r; cin >> l >> r;

    cout << "YES\n";
    for (ll i = l; i<=r; i+=2)
    {
        cout << i << " " << i + 1 << endl;
    }

    return 0;
}


