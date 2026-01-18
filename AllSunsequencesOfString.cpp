#include<iostream>
#include<vector>
#include<string>
 
using namespace std;

vector<string> getSubsequences(string s) {
    int n = s.size();

    int total = (1<<n);
    vector<string> Subsequences;

    for(int mask=0; mask<total;mask++){
        string subseq = "";
        for(int i=0;i<n;i++){
            if(mask &(1<<i)){
                subseq += s[i];
            }
        }
        Subsequences.push_back(subseq);
    }
    return Subsequences;
}

int main(){
    string s = "abc";

    vector<string> result = getSubsequences(s);
    for(auto str : result) {
        cout<<str<<endl;
    }
}