//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])throws IOException
        {
            BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            while(t-->0)
                {
                    String arr[] = br.readLine().split(" ");
                    String A = arr[0];
                    String B = arr[1];
                    Solution obj = new Solution();
                    System.out.println(obj.transform (A, B));
                
System.out.println("~");
}
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    int transform (String A, String B)
    {
        // code here
        HashMap<Character,Integer> hm=new HashMap<>();
        for(int i=0;i<A.length();i++)
        {
            char a=A.charAt(i);
            hm.put(a,hm.getOrDefault(a,0)+1);
        }
        for(int i=0;i<B.length();i++)
        {
            char b=B.charAt(i);
            if(hm.containsKey(b))
            {
                hm.put(b,hm.get(b)-1);
                if(hm.get(b)==0){
                    hm.remove(b);
                }
            }
            else{
                return -1;
            }
        }
        if(hm.size()!=0) return -1;
        int i=A.length()-1;
        int j=B.length()-1;
        int count=0;
        while(i>=0&&j>=0)
        {
            if(A.charAt(i)==B.charAt(j)){
                i--;
                j--;
            }
            else{
                i--;
                count++;
            }
        }
        return count;
    }
}