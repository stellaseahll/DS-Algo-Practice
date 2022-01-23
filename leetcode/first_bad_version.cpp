// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int recursive(long left, long right){
        if (left > right){
            return -1;
        }
        if (left == right){
            if (isBadVersion(left)) {return left;}
            return left+1;
        }
        if (right-left == 1){
            if (isBadVersion(left)){return left;}
            if (isBadVersion(right)){return right;}
            return right+1;
        }
        long mid = (left + right)/2;
        if (isBadVersion(mid)){
            return recursive(left, mid-1);
        }
        else{
            return recursive(mid+1, right);
        }

    }
    int firstBadVersion(int n) {
        return recursive(1, n);
    }
};