class Solution {
public:
    string multiplyOne(string num1, char c){
        int res = 0;
        string s = "";
        for (int j = num1.size()-1; j >= 0; j--){
            
            int x = (num1[j]-'0')*(c-'0') + res;
            res = x/10;
            s = (char) ('0'+x%10) + s;
        }
        if (res != 0){
            s = (char) ('0'+res) + s;
        }
        return s;
    }
    string add(string num1, string num2){
        int res = 0;
        string s = "";
        int i = num1.size()-1, j = num2.size()-1;
        while (i>=0 && j >= 0){
            int x = (num1[i--]-'0') + (num2[j--]-'0') + res;
            res = x/10;
            s = (char) ('0'+x%10) + s;
        }
        while (i>=0){
            int x = (num1[i--]-'0') + res;
            res = x/10;
            s = (char) ('0'+x%10) + s;
        }
        while (j>=0){
            int x = (num2[j--]-'0') + res;
            res = x/10;
            s = (char) ('0'+x%10) + s;
        }
        if (res != 0){
            s = (char) ('0'+res) + s;
        }
        return s;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {return "0";}
        int idx1 = num1.size()-1;
        int idx2 = num2.size()-1;
        string s = "0";
        if (idx1 > idx2){
            for (int j = idx2; j >= 0; j--){
                int numZero = idx2-j;
                s = add(s,multiplyOne(num1,num2[j]) + string(numZero,'0'));
            }
        }
        else{
            for (int j = idx1; j >= 0; j--){
                int numZero = idx1-j;
                s = add(s,multiplyOne(num2,num1[j]) + string(numZero,'0'));
            }
        }
        return s;
    }
};