#include <iostream>
#include <string>

using namespace std;


int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int needed = 0;
        int l = 0;
        cin >> l;
        string r;
        cin >> r;
        int e = 0;
        for (int i = 0; i <= l; i++) {
            if (i < l && r[i] == '.') e++;
            else if (e){
                needed += (e > 1) ? 2 : 1;
                if (e > 2) {
                    needed = 2;
                    break;
                };
                e = 0;
            }
        }

        cout << needed << "\n";
    }

    return 0;
}
