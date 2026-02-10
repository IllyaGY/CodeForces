#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
 
 
    int t ;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n);
        vector<long long> b(n);
 
        // vector<int> rightSum(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        for (int i = a.size()-1; i >= 0; i--) {
            a[i] = max(a[i], max(b[i], (i + 1 < a.size() ? a[i+1] : 0)));
            // rightSum[i] = (i + 1 < a.size() ? rightSum[i + 1] : 0) + a[i];
        }
        vector<long long> leftSum = a;
        for (int i = 1; i < a.size(); i++) {
            leftSum[i] += leftSum[i-1];
        }
 
        for (int i = 0; i < q; i++) {
            int l, r; cin >> l >> r;
            l--, r--;
            cout << leftSum[r] - (l >= 1 ? leftSum[l-1] : 0) << " ";
        }
        cout << "\n";
    }
 
 
    return 0;
}
