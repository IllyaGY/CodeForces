#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n;
    cin >> n;
    vector<ll> v2 (3, 0);
    while (n--)
    {
        ll tmp; cin >> tmp; v2[tmp]++;
    }
    ll sum = 0;
    if (v2[2]) {sum += 2; v2[2]--; cout << 2 << " ";}
    if (v2[1]) {sum += 1; v2[1]--; cout << 1 << " ";}
    while (v2[2]--) {sum+=2; cout << 2 << " "; }
    while (v2[1]--) {sum+=1; cout << 1 << " "; }
    return 0;
}
