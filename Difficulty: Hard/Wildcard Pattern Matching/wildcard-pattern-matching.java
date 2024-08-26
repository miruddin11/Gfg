//{ Driver Code Starts
import java.util.*;

class WildcardPattern {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t > 0) {
            String pat = sc.nextLine();
            String text = sc.nextLine();
            Solution g = new Solution();
            System.out.println(g.wildCard(pat, text));
            t--;
        }
    }
}
// } Driver Code Ends




class Solution
{
    public static boolean isMatch(String s,String p)
    {
        int n=s.length(),m=p.length();
        boolean dp[][]=new boolean[n+1][m+1];
        //initialize
        dp[0][0]=true;
        //pattern=" "
        for(int i=1;i<n+1;i++)
        dp[i][0]=false;

        //s=" "
        for(int j=1;j<m+1;j++)
        {
            if(p.charAt(j-1)=='*') dp[0][j]=dp[0][j-1];
            else dp[0][j]=false;
        }

        //bottom up
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s.charAt(i-1)==p.charAt(j-1)||p.charAt(j-1)=='?')
                dp[i][j]=dp[i-1][j-1];
                else if(p.charAt(j-1)=='*')
                dp[i][j]=dp[i][j-1]||dp[i-1][j];
                else
                dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
    int wildCard(String pattern, String str)
    {
        // Your code goes here
        return isMatch(str, pattern)==true?1:0;
    }
}
