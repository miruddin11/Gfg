//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        if(n==1){
            return {-1};
        }
        stack<int> s;
        s.push(arr[n-1]);
        vector<int> rs(n,-1);
        rs[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty()&&s.top()>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                rs[i]=s.top();
            }
            s.push(arr[i]);
        }
        return rs;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends