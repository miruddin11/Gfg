class Solution:
    def sort012(self, arr):
        # code here
        cntZero, cntOne = 0,0
        for i in range(0,len(arr)):
            if arr[i]==0 :
                cntZero+=1
            elif arr[i]==1 :
                cntOne+=1
                
        for i in range(0,len(arr)):
            if i<cntZero :
                arr[i]=0
            elif i<cntZero+cntOne :
                arr[i]=1
            else :
                arr[i]=2
        