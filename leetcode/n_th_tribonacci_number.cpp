class Solution {
public:
    int tribonacci(int n) {
        if (n==0) {return 0;}
        if (n<=2) {return 1;}
        int f0 = 0, f1 = 1, f2 = 1;
        for (int i = 3; i <= n; i++){
            int tmp = f0+f1+f2;
            f0 = f1; 
            f1 = f2;
            f2 = tmp;
        }
        return f2;
    }
};