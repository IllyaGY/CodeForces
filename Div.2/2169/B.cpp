#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

typedef long long ll;

using namespace std;

unordered_set<string> inf_comb = {"**", ">*", "*<", "><"};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    ll t; cin >> t;


    while (t--)
    {

        ll mx = 0;
        string s; cin >> s;
        ll cur_l = 0;
        ll cur_r = 0;
        for (ll i = 0, j = s.length()-1; i < s.length(); i++, j--) // left to right >>>> ...
        {
            if (i+1 < s.length() && inf_comb.find(s.substr(i, 2)) != inf_comb.end())
            {
                mx = -1;
                break;
            }
            if (s[i] == '<')
            {
                mx = max(mx, cur_l);
                cur_l = 0;
            }
            else cur_l++;

            if (s[i] == '>')
            {
                mx = max(mx, cur_r);
                cur_r = 0;
            }
            else cur_r++;

            mx = max(mx, max(cur_r, cur_l));
        }
        cout << mx << "\n";


    }
    return 0;
}
