
class Solution {
public:
    void countWays(long long  *arr, int& count, int left, int right, int& lower, int& upper){
        int mid = (right+left)/2;
        int r2 = mid+1;
        int r1 = mid+1;
        
        for (int j = left; j <= mid; j++){
            while (r1 <= right && arr[r1]-arr[j] <= (long long) upper ){
                r1++;
            }
            while (r2 <= right && arr[r2]-arr[j] < (long long) lower){
                r2++;
            }
            count += (r1-r2);
        }
        return;
    }
    
    void merge(long long  *arr, int left, int right, int& lower, int& upper, int& count){
        int mid = (left + right)/2;
        int nl = mid-left+1;
        int nr = right - mid;
        int lstart = left;
        int rstart = mid+1;
        long long tmp[right-left+1];
        // vector<long> tmp;
        int li = lstart;
        int ri = rstart;
        int i = 0;
        while (li < lstart+nl && ri < rstart+nr ){
            if (arr[li] < arr[ri]){
                tmp[i++] = arr[li++];
                // li++; /
            }
            else{
                tmp[i++] = arr[ri++];
                // ri++;
            }
        }
        while (li <  lstart+nl){
            tmp[i++] = arr[li++];
            // li++;
        }
        while (ri < rstart+nr){
            tmp[i++] = arr[ri++];
        }
        for (int j = 0; j < right-left+1; j++){
            arr[lstart+j] = tmp[j]; 
        }
    }
    
    void mergeSort(long long  *arr, int& lower, int& upper, int& count, int left, int right){
        if (left >= right){return;}
        int mid = (left+right)/2;
        mergeSort(arr, lower, upper, count, left, mid);
        mergeSort(arr, lower, upper, count, mid+1, right);
        countWays(arr, count, left, right, lower, upper);
        merge(arr,left,right, lower, upper, count);
    }
    
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long sum[n+1];
        sum[0] = 0;
        int count = 0;
        for (int j = 0; j < n; j++){
            sum[j+1] = sum[j] + nums[j];    
        }
        mergeSort(sum, lower, upper, count, 0, n);
        return count;
        
    }
};