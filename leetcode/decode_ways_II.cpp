class Solution {
public:

    int prod(int x, int n){
        int ans = 0;
        int X =  1000000007;
        while (n--){
            ans += x%X;
            ans = ans%X;
        }
        return ans;
    }
 
    int singleCount(char c){
        if (c=='*'){
            return 9;
        }
        if (c=='0'){
            return 0;
        }
        return 1;
    }
    int doubleCount(char c1, char c2){
        if (c1 =='*' && c2 == '*'){return 15;}
        if (c1 =='*' && (c2 >= '0' && c2 <= '6')) {return 2;}
        if (c1 == '*') {return 1;}
        if (c1 == '1' && c2 == '*'){return 9;}
        if (c1 == '1'){return 1;}
        if (c1 == '2' && c2 == '*'){return 6;}
        if (c1 == '2' && (c2 >= '0' && c2 <= '6')){return 1;}
        return 0;
        
    }
    
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0){
            return 0;
        }
        if (n==1){return singleCount(s[0]);}
        if (n==2){return singleCount(s[1])*singleCount(s[0]) + doubleCount(s[0],s[1]);}
        vector<int> memo(n,-1);
        memo[n-1] = singleCount(s[n-1]);
        memo[n-2] = singleCount(s[n-1])*singleCount(s[n-2]) + doubleCount(s[n-2],s[n-1]);
        for (int j = n-3; j >= 0; j--){
            memo[j] = (prod(memo[j+1],singleCount(s[j])) + prod(memo[j+2],doubleCount(s[j],s[j+1])))%1000000007;
        }
        return memo[0];
        
    }

};