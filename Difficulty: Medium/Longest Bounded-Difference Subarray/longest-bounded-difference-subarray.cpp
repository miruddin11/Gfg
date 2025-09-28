class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        deque<int> maxDq, minDq;
        int left = 0, bestStart = 0, bestLen = 0;
    
        for (int right = 0; right < n; right++) {
            while (!maxDq.empty() && arr[maxDq.back()] < arr[right]) 
                maxDq.pop_back();
            maxDq.push_back(right);
    
            while (!minDq.empty() && arr[minDq.back()] > arr[right]) 
                minDq.pop_back();
            minDq.push_back(right);
    
            while (arr[maxDq.front()] - arr[minDq.front()] > x) {
                if (maxDq.front() == left) maxDq.pop_front();
                if (minDq.front() == left) minDq.pop_front();
                left++;
            }
    
            if (right - left + 1 > bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
        }
    
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
    }
};