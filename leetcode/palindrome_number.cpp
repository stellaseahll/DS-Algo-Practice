class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){return false;}
        vector<int> digits; 
        while (x>0){
            digits.push_back(x%10);
            x/=10;
        }
        for (int j = 0; j < digits.size()/2; j++){
            if (digits[j]!=digits[digits.size()-1-j]){return false;}
            
        }
        return true;
    }
};