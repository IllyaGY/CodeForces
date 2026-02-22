#include <iostream>

using namespace std;

int main() {

    int tests = 0;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;

        int mx = 1;
        for (int i = 1 ; i <= k && i*i<=n; i++){
            if (!(n % i)) {
                int j = n / i;
                if (j <= k) {
                    mx = j;
                    break;
                }
                else mx = i;
            }
        }
        cout << n/mx << "\n";
    }
    return 0;
}

