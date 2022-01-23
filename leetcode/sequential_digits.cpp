class Solution {
public:
    int getOnes(int n){
        if (n == 0){return 0;}
        int x = 1;
        for (int j = 1; j < n; j++){
            x = x*10 + 1;
        }
        return x;
    }
    int getNumDigits(int n){
        int x = 0;
        while (n>0){
            n = n/10;
            x++;
        }
        return x;
    }
    int getStart(int n){
        int x = 0;
        int i = 1;
        while (i<=n){
            x = x*10 + i;
            i++;
        }
        return x;
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int lowD = getNumDigits(low);
        int highD = getNumDigits(high);
        for (int j = lowD; j <= highD ; j++){
            int start = getStart(j);
            int num = start;
            int diff = getOnes(j);
            for (int k = 0; k < 10-j; k++){
                if (num >= low && num <= high){
                    ans.push_back(num);
                }
                num+=diff;
            }
        }
        return ans;
    }
};