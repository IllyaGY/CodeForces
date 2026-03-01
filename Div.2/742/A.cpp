#include <iostream>
#include <vector>
 
#define LL_RET(L, x) (((L + x - 1) / x) * x)
 
using namespace std;
typedef long long ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll b, e;
    b= 1378;
    cin >> e;
    ll f = 1;
    b %= 10;
    while (e >= 1) {
        if (e % 2) f = (f * b) % 10;
 
        b = (b * b)% 10;
 
        e/=2;
    }
    cout << f % 10;
    return 0;
}
