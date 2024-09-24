#User function Template for python3


class Solution:
    def smallestWindow(self, s, p):
        if len(p) > len(s):
            return "-1"
        
        char_count = {}
        for char in p:
            char_count[char] = char_count.get(char, 0) + 1
        
        required = len(char_count)
        left, right = 0, 0
        formed = 0
        window_counts = {}
        min_window_length = float("inf")
        min_window_start = 0
        while right < len(s):
            char = s[right]
            window_counts[char] = window_counts.get(char, 0) + 1
            
            if char in char_count and window_counts[char] == char_count[char]:
                formed += 1
            
            while left <= right and formed == required:
                if right - left + 1 < min_window_length:
                    min_window_length = right - left + 1
                    min_window_start = left
                
                left_char = s[left]
                window_counts[left_char] -= 1
                
                if left_char in char_count and window_counts[left_char] < char_count[left_char]:
                    formed -= 1
                
                left += 1
            
            right += 1
        
        return "-1" if min_window_length == float("inf") else s[min_window_start:min_window_start + min_window_length]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        s=str(input())
        p=str(input())
        ob = Solution()
        print(ob.smallestWindow(s,p))
# } Driver Code Ends