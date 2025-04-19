//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    struct Trie {
        Trie* children[2] = {nullptr, nullptr};
    };
    Trie* root = new Trie();
    void insertNumber(int num) {
        Trie* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new Trie();
            }
            curr = curr->children[bit];
        }
    }
    int getMaxXor(int num) {
        Trie* curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->children[0] == nullptr && curr->children[1] == nullptr) {
                return -1;
            }
            if (bit == 0) {
                if (curr->children[1]) {
                    ans |= (1 << i);
                    curr = curr->children[1];
                } else {
                    curr = curr->children[0];
                }
            } else {
                if (curr->children[0]) {
                    ans |= (1 << i);
                    curr = curr->children[0];
                } else {
                    curr = curr->children[1];
                }
            }
        }
        return ans;
    }
    int maxXor(vector<int> &nums) {
        // code here
        if (nums.size() < 2) return 0;
        for (int num : nums) {
            insertNumber(num);
        }
        int maxXorValue = nums[0] ^ nums[1];
        for (int num : nums) {
            maxXorValue = std::max(maxXorValue, getMaxXor(num));
        }
        return maxXorValue;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends