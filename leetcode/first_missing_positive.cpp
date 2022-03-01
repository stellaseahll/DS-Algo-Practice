class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int min = 2147483647;
        int max = 1;
        int numPos = 0;
        for (int j = 0; j< nums.size(); j++){
            if (nums[j]>0){
                numPos++;
                if (nums[j]>max){
                    max = nums[j];
                }
                if (nums[j]<min && nums[j]>0){
                    min = nums[j];
                }
            }
            else{
                nums[j] = 0;
            }
        }
        if (min > 1){return 1;}
        int ans = max;
        for (int j = 0; j< nums.size(); j++){
            if (nums[j]>numPos && nums[j] < max){
                max=nums[j];
            }
            if (nums[j]>0 && nums[j]<=numPos){
                // cout<< j << " "<< nums[j]<< endl;
                int curr = nums[j]; 
                int next = nums[curr-1];
                if (next == 0 || next > numPos || curr-1 <= j){
                    nums[curr-1] = -1;
                    continue;
                }
                while (curr-1 > j && (next <= numPos && next > 0)){
                    // cout << curr << " " << next << endl;
                    nums[curr-1] = -1;
                    curr = next;
                    next = nums[curr-1];
                }
                nums[curr-1] = -1;
            }
            for (int j = 0; j < nums.size(); j++){
            cout << nums[j] <<" "; 
            }
            cout << endl;
        }
        for (int j = 0; j<numPos; j++){
            if (nums[j]!=-1){
                return j+1;
            }
        }
        if (numPos == max){return max+1;}
        return ans;
    }
};