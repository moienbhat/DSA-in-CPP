#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int cntCows = 1, last = stalls[0];

    for(int i=0;i<stalls.size();i++) {
        if(stalls[i] - last >= dist){
        cntCows++;
        last = stalls[i];
    }
      if(cntCows >= cows) return true;
    }
    return false;
  
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0];

    while(low <= high) {
        int mid = (low + high)  / 2;
        if(canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }
    }

    return high;
}


int main() {

       vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";


    return 0;
}