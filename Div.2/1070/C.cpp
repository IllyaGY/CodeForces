
#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;
typedef std::vector<long long> v;

void func() {
    int nums = 0;
    std::cin >> nums;
    v even, odd;

    int e = 0;
    long long evenSum = 0;
    while (nums--) {
        int temp = 0;
        std::cin >> temp;
        if (temp%2) odd.push_back(temp);
        else {
            even.push_back(temp);
            e++;
            evenSum += temp;
        }

    }

    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    nums = even.size() + odd.size();



    long long topOdd = 0;
    if (!odd.empty()) {
        topOdd = odd.back();
        odd.pop_back();
    }
    else {
        for (int i = 0; i < nums; i++) std::cout << 0 << " ";
        return;
    }
    long long totalBest = evenSum + topOdd;
    int bestCount = e + 1;

    vector<long long> bests (bestCount, 0);


    for (int i = 1; i < bests.size(); i++) bests[i] = bests[i-1] + even[i-1];
    bests.push_back(bests[bests.size()-1] + topOdd);


    for (int i = 1; i <= nums; i++) {
        long long cap = totalBest;
        if (bestCount > i) {
            cap -= bests[bestCount - i];
        }
        else if (bestCount < i) {
            if ((i - bestCount) % 2 == 1){
                if (even.size() > 0) {
                    cap  -= even[0];
                }
                else cap = 0;

                if (i - bestCount == odd.size()) cap = 0;
            }

        }
        std::cout << cap << " ";
    }
}


int main() {

    int s = 0;
    cin >> s;
    while (s--) {
        func();
        cout << "\n";
    }




    return 0;
}

