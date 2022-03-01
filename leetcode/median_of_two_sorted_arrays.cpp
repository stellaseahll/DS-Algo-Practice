class Solution {
public:
    double getConsecutiveMedian(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size();
        int n = nums2.size();
        double sum;
        int idx = (m+n)/2;
        if (idx < m){
            sum = nums1[idx];
        }
        else{
            sum = nums2[idx-m];
        }
        if ((m+n)%2==0){
            int idx2 = idx-1;
            if (idx2 < m){
                sum += nums1[idx2];
            }
            else{
                sum += nums2[idx2-m];
            }
            sum /= 2;
        }
        return sum;
    }
    double getMedian(const vector<int>& nums1,const vector<int>& nums2,int left,int right){
        if (left > right){
            return -1000000000;
        }
        int m = nums1.size();
        int n = nums2.size();
        int mid = (left+right)/2;
        int midVal = nums1[mid];
        int idx2 = upper_bound(nums2.begin(),nums2.end(),midVal) - nums2.begin();
        int nL = mid + idx2;
        int nR = (m-1-mid) + n - idx2;
        while (abs(nL-nR) > 1 && idx2 > 0 && nums2[idx2-1] == midVal){
            idx2--;
            nL = mid+idx2;
            nR = (m-1-mid) + n - idx2;
        }
        if (nL == nR){
            return midVal;
        }
        if (nL == nR+1){
            double sum = midVal;
            if (idx2 == 0){
                sum += nums1[mid-1];
            }
            else if (mid == 0){
                sum += nums2[idx2-1];
            }
            else{
                sum += max(nums1[mid-1],nums2[idx2-1]);
            }
            return sum/2.0;
        }
        else if (nL+1 ==nR){
            double sum = midVal;
            if (mid == m-1){
                sum += nums2[idx2];
            }
            else if (idx2 == n){
                sum += nums1[mid+1];
            }
            else{
                sum += min(nums1[mid+1],nums2[idx2]);
            }
            return sum/2.0;
        }
        if (mid + idx2 > (n-idx2+m-mid)){
            return getMedian(nums1,nums2,left,mid-1);
        }
        return getMedian(nums1,nums2,mid+1,right);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0){
            if (n%2 == 0){
                return (nums2[n/2]+nums2[n/2-1])/2.0;
            }
            return nums2[n/2];
        }
        if (n == 0){
            if (m%2 == 0){
                return (nums1[m/2]+nums1[m/2-1])/2.0;
            }
            return nums1[m/2];
        }
        if (nums1[m-1] <= nums2[0]){
           return getConsecutiveMedian(nums1,nums2);
        }
        else if (nums2[n-1] <= nums1[0]){
            return getConsecutiveMedian(nums2,nums1);
        }
        double ans = getMedian(nums1,nums2,0,m-1);
       
        if (ans < -999999999){
            return getMedian(nums2,nums1,0,n-1);
        }
        return ans;
    }
};