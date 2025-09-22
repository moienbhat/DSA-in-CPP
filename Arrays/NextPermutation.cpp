#include <iostream>
#include <vector>
#include <algorithm>  // for reverse, swap
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    int ind = -1;
    int n = A.size();

    // Step 1: Find the first index from the back where A[i] < A[i+1]
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

    // If no such index, it's the last permutation
    if (ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find element just greater than A[ind] from the right
    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: Reverse the suffix
    reverse(A.begin() + ind + 1, A.end());
    return A;
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = nextGreaterPermutation(arr);

    cout << "Next Greater Permutation: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
