//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[101][101];
    int solve(int i,int j,vector<int> &arr)
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        for(int k=i;k<j;k++)
        {
            int temp=solve(i,k,arr)+solve(k+1,j,arr)+arr[i-1]*arr[k]*arr[j];
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int N=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(1,N-1,arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends