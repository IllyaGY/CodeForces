#include <iostream>
#include <vector>
#include <algorithm> 

typedef long long ll; 

using namespace std; 

int main()
{
    ll t = 0; cin >> t; 
    while(t--){
        ll a, b; cin >> a >> b;
        if (a > b)
        {
            if ((a ^ b) < a)
            {
                cout << 1 << "\n";
                cout << (a ^ b) << "\n";
            }
            else
            {
                cout << 2 << "\n";
                cout << b << " " << a << "\n";
            }
        }
        else if (a < b)
        {
            if ((a ^ b) < a)
            {
                cout << 1 << "\n"; 
                cout << (a ^ b) << "\n";
            }
            else
                cout << -1 << "\n";
        }
        else cout << 0 << "\n";
    }
    
    
    return 0; 
}