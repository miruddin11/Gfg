//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[505][505];
    int solve(int i,int j,string &str)
    {
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str[i]==str[j]){
            return solve(i+1,j-1,str);
        }
        int x=solve(i+1,j,str);
        int y=solve(i,j-1,str);
        return dp[i][j]=1+min(x,y);
    }
    int countMin(string str){
        memset(dp,-1,sizeof(dp));
        return solve(0,str.size()-1,str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends