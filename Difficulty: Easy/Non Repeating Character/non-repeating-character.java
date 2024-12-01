//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class Driverclass {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String st = sc.next();

            char ans = new Solution().nonRepeatingChar(st);

            if (ans != '$')
                System.out.println(ans);
            else
                System.out.println(-1);

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to find the first non-repeating character in a string.
    static char nonRepeatingChar(String s) {
        // Your code here
        LinkedHashMap<Character,Integer> lhm=new LinkedHashMap<>();
        for(int i=0;i<s.length();i++)
        {
            char ch=s.charAt(i);
            if(lhm.containsKey(ch))
            {
                lhm.put(ch,lhm.get(ch)+1);
            }
            else{
                lhm.put(ch,1);
            }
        }
        
        char ans='$';
        for(Map.Entry<Character,Integer> i:lhm.entrySet())
        {
            if(i.getValue()==1){
                ans=i.getKey();
                break;
            }
        }
        return ans;
    }
}
