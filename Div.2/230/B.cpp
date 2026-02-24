#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
 
int main() {
    int t = 0;
    cin >> t;
    vector<long long> v(1000001, 1);
    v[1] = 0;
    for (long long i = 2; i <= 1000000; i++) {
        if (!v[i]) continue;
        long long j = i * i;
        while (j <= 1000000)  {
            if (v[j]) v[j] = 0;
            j+=i;
        }
 
    }
    while (t--) {
        long long n;
        cin >> n;
        long long val = sqrt(n);
        if (val * val != n || !v[val]) {
            cout << "NO\n";
            continue;
        }
 
        cout << "YES\n";
    }
    return 0;
}
