#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    ll c = 0;
    while(m > n){
        c += m % 2;
        m= (m + (m%2)) / 2;
        c++;
    }
    c+= n - m;
    cout << c;
    return 0;
}
