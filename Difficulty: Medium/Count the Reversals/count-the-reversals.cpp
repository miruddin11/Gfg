//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    int n=s.size();
    if(n%2==1){
        return -1;
    }
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(!st.empty()&&s[i]=='}'&&st.top()=='{')
        {
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    int open=0,close=0;
    while(!st.empty())
    {
        if(st.top()=='{'){
            open+=1;
        }
        else{
            close+=1;
        }
        st.pop();
    }
    int a=(open+1)/2;
    int b=(close+1)/2;
    return a+b;
}