class Solution {
public:
    int distinctSubseqII(string s) {
        int modulo = 1000000007;
        int prevCount = 1;
        int totalCount = 1;
        map<char,long> m;
        m[s[0]] = 1;
        for (int j = 1; j < s.size(); j++){
            char c = s[j];
            int currCount = (prevCount + 1)%modulo;
            if (m.count(c)==0){
                totalCount += currCount;  
                totalCount = totalCount%modulo;
                if (totalCount < 0) {totalCount += modulo;}
                m[c] = currCount;// take into account empty string
                prevCount = totalCount;
            }
            else{
                totalCount += (currCount%modulo - m[c]%modulo)%modulo ;
                totalCount = totalCount%modulo;
                if (totalCount < 0) {totalCount += modulo;}
                m[c]  = currCount;
                prevCount = totalCount;
            }
        }
        return totalCount;
    }
};