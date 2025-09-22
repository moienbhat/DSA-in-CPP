#include<iostream>
#include<vector>
using namespace std;

// vector<int> rearrange(int arr[], int n) {            Variety 1
//     int posIndex = 0, negIndex = 1;
//     vector<int> ans(n);
    
//     for(int i = 0; i < n; i++) {
//         if (arr[i] < 0) {
//             ans[negIndex] = arr[i];
//             negIndex += 2;
//         } else {
//             ans[posIndex] = arr[i];
//             posIndex += 2;
//         }
//     }
//     return ans;
// }



//  variety 2

vector<int> alternateNumbers(vector<int>&a) {
    vector<int> pos, neg;
    int n = a.size();
    for(int i =0; i< n; i++) {
        if(a[i] > 0)
            pos.push_back(a[i]);

        else{
            neg.push_back(a[i]);
        }
    }

    if(pos.size() > neg.size()) {
        for(int i =0;i<neg.size();i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++) {
            a[index] = pos[i];
            index ++;
        }
    }

    else 
    {
        for(int i =0;i<pos.size();i++) {
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++) {
            a[index] = neg[i];
            index ++;
        }
    }
return a;

}

int main(){
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
     vector<int> arr(n);  // ✅ use vector instead of raw array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = alternateNumbers(arr);



    cout << "Rearranged array: ";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
