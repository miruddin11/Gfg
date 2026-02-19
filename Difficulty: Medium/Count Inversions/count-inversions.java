class Solution {
    static int count = 0;
    static void merge(int arr[] , int left , int mid , int right) {
        int n = arr.length;
        int temp[] = new int[right - left + 1];
        int i = left;
        int j = mid + 1;
        int k = 0;
        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                count += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }
        while(i <= mid) {
            temp[k++] = arr[i++];
        }
        while(j <= right) {
            temp[k++] = arr[j++];
        }
        for (int t = 0; t < temp.length; t++) {
            arr[left + t] = temp[t];
        }
    }
    static void mergeSort(int arr[] , int left , int right) {
        if(left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr , left , mid);
        mergeSort(arr , mid + 1 , right);
        merge(arr, left , mid , right);
    }
    static int inversionCount(int arr[]) {
        // Code Here
        int n = arr.length;
        count = 0;
        mergeSort(arr , 0 , n - 1);
        return count;
    }
}