//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<pair<int,int>> dp(n);
	    int maxSum=0;
	    for(int i=0;i<n;i++)
	    {
	        dp[i].first=1;
	        dp[i].second=arr[i];
	        maxSum=max(maxSum,arr[i]);
	    }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j]){
                    dp[i].first=max(dp[i].first,dp[j].first+1);
                    dp[i].second=max(dp[i].second,dp[j].second+arr[i]);
                    maxSum=max(maxSum,dp[i].second);
                }
            }
        }
        return maxSum;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends