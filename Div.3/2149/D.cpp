#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(){
    ll t; cin >> t;

    while (t--)
    {
        ll size; cin >> size;
        string s; cin >> s;
        ll a = 0, b = 0;
        for (auto &i : s ) {
            if (i == 'a')
                a++;
            else b++;
        }
        //doing for b, checking how many a's are in the way
        ll left = 0, right = a;
        ll b_steps = 0;
        ll a_steps = 0;
        for (auto &i : s)
        {
            if (i == 'a') {left++; right--;}
            else b_steps+=min(left, right);
        }
        left = 0, right = b;
        for (auto &i : s)
        {
            if (i == 'b') {left++; right--;}
            else a_steps+=min(left, right);
        }
        cout << min(a_steps, b_steps) << endl;
    }
    return 0;
}