// C - Less or Equal 

#include <algorithm>
#include <iostream>
#include<vector>
int main() {
    int i = 0, k = 0;
    std::cin >> i >> k;
    std::vector<int> v;
    while (i--) {
        int t; std::cin >> t;
        v.push_back(t);
    }
    std::sort(v.begin(), v.end());
    i = 0;
    int ct = 1; // index
    while (i < v.size() && ct == v[i]) i++;
    for (; i < v.size();) {
        if (i == k) break;
        if (i < v.size()-1 && v[i] == v[i+1]) {
            while (i < v.size()-1 && v[i] == v[i+1]) {
                i++;
            }
 
        }
        ct = v[i];
        i++;
    }
    std::cout << (i == k ? ct : -1);
    return 0;
}
