#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
    int n = arr.size();
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Prefix sum 0 initially occurs once.

    for (int i = 0; i < n; i++) {
        preSum += arr[i];

        int remove = preSum - k;

        cnt += mpp[remove];  // Add number of times (preSum-k) appeared.

        mpp[preSum]++;       // Store/update current prefix sum.
    }
    return cnt;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
