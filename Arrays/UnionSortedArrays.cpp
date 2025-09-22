#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// vector < int > sortedArray(int arr1[], int arr2[], int n, int m) {
//     set<int> st;
//     for(int i = 0;i<n;i++){
//         st.insert(arr1[i])
//     }
//     for(int i = 0;i<m;i++){
//         st.insert(arr2[i])
//     }

//     vector <int> tenp;
//     for(auto it: st) {
//         temp.push_back(it);
//     }

//     return temp;

    


// }

vector <int> unionArrays(vector <int> a, vector <int> b) {
    int n1 = a.size();
    int n2 = b.size();
    int i , j = 0;

    vector<int> unionArr;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{

            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
        }

        while(j < n2){
               if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;

        }


        while(i<n1){
                if(unionArr.size() == 0 || unionArr.back() != a[i]){
                 unionArr.push_back(a[i]);
                }
                i++;
        }
        return unionArr;
    }





int main() {
    int n;
    cout << "Enter number of elements in first array: ";
    cin >> n;

    int arr[n]; // works in GCC/Clang, but use vector<int> in standard C++
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }



    int m;
    cout << "Enter number of elements in second array: ";
    cin >> m;

    int arr[m]; // works in GCC/Clang, but use vector<int> in standard C++
    cout << "Enter elements: ";
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }




    
   
        
    return 0;
}



