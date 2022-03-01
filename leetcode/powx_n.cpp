class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0){return 1;}
        double curr;
        double y = 1;
        if (n > 0){
            curr = x;
        }
        else{
            curr = 1/x;
            if (n == -2147483648){
                y = 1/x;
                n = 2147483647;
            }
            else{
                n = -n;
            }
        }
        
        while (n > 0){
            if (n&1){ 
                y = y*curr;
            }
            curr = curr*curr;
            n = (n >> 1);
        }
        return y;
    
    }
};