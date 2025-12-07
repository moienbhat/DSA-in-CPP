#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    int lengthOfLCS(string s) {
        vector <int> mpp(256, -1);

        int left = 0;
        int right = 0;
        int n = s.size();
        int len = 0;

        while(right < n) {
            if(mpp[s[right]] != -1) 
                left = max(mpp[s[right]] + 1, left);

            mpp[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
           

        }

        return len;
    }
};

int main() {

    string str = "ColdWater";
    Solution obj;
    cout << "Thr length of LCS without repeating characters is: " << obj.lengthOfLCS(str);



    return 0;
}