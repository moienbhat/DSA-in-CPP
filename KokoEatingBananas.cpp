#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int CalculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    for (int i = 0; i < v.size(); i++) {
        totalH += ceil((double)v[i] / (double)hourly);
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int l = 1, high = findMax(v);
    while (l <= high) {
        int mid = (l + high) / 2;
        int totalH = CalculateTotalHours(v, mid);

        if (totalH <= h) {
            high = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat at least " << ans << " bananas/hr.\n";
    return 0;
}
