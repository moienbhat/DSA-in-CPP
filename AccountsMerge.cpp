#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

// Disjoint Set (Union-Find) implementation
class DisjointSet {
    vector<int> rank, parent, size;
public:
    // Constructor to initialize DSU
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        // Initialize every node
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Function to find ultimate parent with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        parent[node] = findUPar(parent[node]);
        return parent[node];
    }

    // Function to perform union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Function to perform union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Solution class to merge accounts
class Solution {
public:
    // Function to merge accounts with common emails
    vector<vector<string>> accountsMerge(
        vector<vector<string>> &details) 
    {
        // Number of accounts
        int n = details.size();

        // Create Disjoint Set
        DisjointSet ds(n);

        // Map to store email -> account index
        unordered_map<string, int> mapMailNode;

        // Step 1: Union accounts having common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2: Group emails under ultimate parent
        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        // Step 3: Prepare final merged result
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(details[i][0]);

            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        // Sort final answer
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Driver function
int main() {
    // Input accounts
    vector<vector<string>> accounts = {
        {"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    // Create Solution object
    Solution obj;

    // Call function
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    // Print output
    for (auto &acc : ans) {
        cout << acc[0] << ":";
        for (int i = 1; i < acc.size(); i++) {
            cout << acc[i] << " ";
        }
        cout << endl;
    }
    return 0;
}