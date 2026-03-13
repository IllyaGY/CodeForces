#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t;
    cin >> n >> t;
    ll k = n;
    ll r = 1;
    ll left = 1;
    while(k-- > 1 && r < t){
        left--;
        ll val;
        cin >> val;
        if(!left){
            r+=val; //it will only reach t here and will get verified right away
            left = val;
        }
        if(r==t){
            cout << "YES" << "\n";
            return 0 ;
        }
        val--;

    }
    cout << "NO";

    return 0;
}
