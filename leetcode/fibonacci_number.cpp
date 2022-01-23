class Solution {
public: //Start: 3:29PM End: 3:31PM
    int fib(int n) {
        if (n==0){return 0;}
        if (n==1){return 1;}
        int f0 = 0, f1 = 1;
        for (int j = 2; j <= n; j++){
            int tmp = f0+f1;
            f0 = f1;
            f1 = tmp;
        }
        return f1;
    }
};