#include <iostream>
#include <vector>
#include <algorithm>  // for reverse, swap
using namespace std;

vector<int> LeaderInArray(vector<int> &a) {
    vector<int> ans;
    int n = a.size();
    int maxi = INT_MIN;
// O(n)
    for(int i=n-1; i>=0; i++) {
        if(a[i] >= maxi)
 {
    ans.push_back(a[i]);
    }
     maxi = max(maxi, a[i]);
}


// O(NlogN)
    sort(ans.begin(), ans.end());
    return ans;
} 
  

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = LeaderInArray(arr);

    cout << "Next Greater Permutation: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
