

// vector<vector<int>> mergeOverlappingArrays(vector<vector<int>> &arr) {
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     vector<vector<int>> ans;
//     for(ont i =0;i <n;i++) {
//         if(ans.empty()  || arr[i][0] > ans.back()[1] ){
//             ans.push_back(arr[i]);
//         }
//         else{
//             ans.back()[1] = max(ans.back()[1], ans[i][1]);
//         }
//     }

//     return ans;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}