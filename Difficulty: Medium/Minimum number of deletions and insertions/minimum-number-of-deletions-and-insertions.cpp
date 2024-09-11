//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	int lcs(string &s,string &t)
	{
	    int n=s.size(),m=t.size();
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=m;j++)
	        {
	            if(i==0||j==0) dp[i][j]=0;
	            else if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
	            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    return dp[n][m];
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    return str1.size()+str2.size()-2*lcs(str1,str2);
	} 
};




//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends