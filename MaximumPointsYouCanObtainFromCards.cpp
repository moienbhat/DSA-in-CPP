#include<iostream>
#include<vector>

using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n  = cardPoints.size();

    int total = 0;
    for(int i = 0; i < k; i++) {
        total+= cardPoints[i];
    }

    int maxPoints = total;

    for(int i=0; i<k; i++) {
        total -= cardPoints[k - 1 - i];

        total += cardPoints[n - 1 - i];

        maxPoints = max(maxPoints, total);
    }
    return maxPoints;
}

int main() {

    vector<int> cards = {1,2,3,4,5,6,1};
    int k = 3;

    cout << " Maximum points you can obtain from cards is : " << maxScore(cards, k) << endl;
    return 0;
}