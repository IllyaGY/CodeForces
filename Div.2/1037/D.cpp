#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n ;
    cin >> n;
    vector<unordered_set<ll>> v(n + 1);
    ll q = n-1;
    while(q--){
        ll f, s;
        cin >> f >> s;
        v[f].insert(s);
        v[s].insert(f);
    }
    v[0].insert(1);
    v[1].insert(0);


    queue<ll> qe;
    ll size = 1;
    ll t = 0;
    while (n--) {
        ll i; cin >> i;
        while (!size && !qe.empty()) {
            t = qe.front();
            qe.pop();
            size = v[t].size();
        }

        if (t == -1 || v[t].find(i) == v[t].end()) {
            cout << "No";
            return 0;
        }
        //removing a parent from each of its children to maintain the size
        v[i].erase(t);
        qe.push(i);
        size--;
        if (!size) t = -1;
    }
    cout << "Yes";
    return 0;
}
