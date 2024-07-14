//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int k=pat.size();
	    vector<int> f(26,0);
	    for(auto &x:pat){
	        f[x-'a']+=1;
	    }
	    int i=0,j=0;
	    int count=0;
	    int n=txt.size();
	    vector<int> mp(26,0);
	    while(j<n)
	    {
	        mp[txt[j]-'a']+=1;
	        if(j-i+1==k){
	            if(mp==f){
	                count+=1;
	            }
	            mp[txt[i]-'a']-=1;
	            i++;
	        }
	        j++;
	    }
	    return count;
	}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends