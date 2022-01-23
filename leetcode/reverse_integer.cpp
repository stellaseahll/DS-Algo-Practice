class Solution {
public: //start: 2:32PM // end: 2:44PM
    int reverse(int x) {
        int MAX = 2147483647;
        int y = 0;
        // bool isPositive = x>0;
        // x = (x>0) ? x : -x;
        while (x>0){
            if (y > MAX/10) {return 0;}
            y = y*10 + x%10;
            x = x/10;
        }
        while (x<0){
            if (y < -MAX/10){return 0;}
            y = y*10 + x%10;
            x = x/10;
        }
        return y;
    }
};