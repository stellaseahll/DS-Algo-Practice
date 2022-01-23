typedef pair<int,string> is;
class Solution {
public:
    string intToRoman(int num) {
        queue<is> q;
        vector<int> v = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> s = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        for (int j = 0; j < v.size(); j++){
            q.push(is(v[j],s[j]));
        }
        string ans = "";
        while (num > 0){
            if (num < q.front().first){
                q.pop();
            }
            else{
                ans = ans + q.front().second;
                num -= q.front().first;
            }
        }
        return ans;
    }
};