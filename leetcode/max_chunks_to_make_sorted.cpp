int INF = 1000000000;
class Solution {
public:
    int split(vector<int>& arr, int left, int right){
        if (left == right){
            return 1;
        }
        if (left + 1 == right){
            if (arr[left] < arr[right]){return 2;}
            return 1;
        }
        int currMax = -INF;
        int currMin = INF;
        int idx = -1;
        int idx2 = -1;
        for (int j = left; j <= right; j++){
            if (arr[j] > currMax){
                currMax = arr[j];
                idx = j;
            }       
            if (arr[j] < currMin){
                currMin = arr[j];
                idx2 = j;
            }
        }
        if (idx2 == left && idx == right){
            return 2 + split(arr, left+1,right-1);
        }
        else if (idx2 == left){
            return 1 + split(arr, left+1,right);
        }
        else if (idx == right){
            return 1 + split(arr,left,right-1);
        }
        if (idx == left || idx2 == right){return 1;}
        int rightMin = INF;
        for (int j = idx; j <= right; j++){
            if (arr[j] < rightMin){
                rightMin = arr[j];
            }
        }
        
        for (int j = 0; j < idx; j++){
            if (arr[j] > rightMin){
                return 1;
            }
        }
        return split(arr,left,idx-1) + split(arr,idx,right);
    }
    int maxChunksToSorted(vector<int>& arr) {
        return split(arr,0,arr.size()-1);
    }
};