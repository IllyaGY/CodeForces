#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
 
int main () {
    vector<int> v(3001, 0);
    for (int i = 2; i < 3001; i++) {
        if (v[i]) continue;
        int j = i + i;
        while (j < 3001) {
            v[j]++;
            j+=i;
        }
    }
    v[1]=0;
 
    long long n = 0;
    cin >> n;
    int ctr = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 2) {
            ctr++;
        }
    }
    cout << ctr << "\n";
 
 
    return 0;
}
