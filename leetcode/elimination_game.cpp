class Solution {
public:
    int eliminate(int start, int end, int diff){
        int nTerms = (end-start)/diff + 1;
        if (nTerms == 1){
            return start;
        }
        if (nTerms == 2){
            return end;
        }
        if (nTerms % 2 == 0){
            return eliminate(end,start+diff,diff*-2);
        }
        return eliminate(end-diff,start+diff,diff*-2);
    }
    int lastRemaining(int n) {
        return  eliminate(1, n, 1);
    }
};