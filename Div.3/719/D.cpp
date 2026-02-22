#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int tests = 0;
    cin >> tests;
    while (tests--) {
        unordered_map<long long, long long> mp;
        vector<int> v;
        int n = 0;
        cin >> n;
        int i = 0;
        long long ctr = 0;
        while (n--) {
            int t;
            cin >> t;
            v.push_back(t);
            mp[t - i]++;
            i++;
        }
        for (auto &i : mp) {
            ctr += i.second * (i.second - 1) / 2;
        }
        cout << ctr << " ";
    }
    return 0;
}

