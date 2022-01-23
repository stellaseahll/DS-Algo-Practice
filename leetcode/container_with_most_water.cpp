class Solution {
public: //Start: 3:17PM End : 3:28PM
    int min(int a, int b){
        if (a<=b){
            return a;
        }
        return b;
    }
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int a = 0;
        while (left < right){
            int cl = height[left], cr = height[right];
            int ca = (right-left)*min(cl,cr); 
            a = (ca > a) ? ca : a;
            if (cr<cl){
                while (right > left && height[right] <= cr){
                    right--;
                }
            }
            else if (cl<cr){
                while (right > left && height[left] <= cl){
                    left++;
                }
            }
            else{
                while (right > left && height[left] <= cl){
                    left++;
                }
                while (right > left && height[right] <= cr){
                    right--;
                }
            }
        }
        return a;
    }
};