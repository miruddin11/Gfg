//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int,int> mp;
        mp[0]=-1;
        int n=arr.size();
        int currSum=0;
        int mxLen=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0){
                currSum-=1;
            }
            else{
                currSum+=1;
            }
            if(mp.find(currSum)!=mp.end()){
                mxLen=max(mxLen,i-mp[currSum]);
            }
            else{
                mp[currSum]=i;
            }
        }
        return mxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends