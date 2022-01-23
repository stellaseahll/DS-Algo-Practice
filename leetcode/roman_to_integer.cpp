typedef pair<int,string> is;
class Solution {
public:
    int romanToInt(string s) {
        queue<is> q;
        vector<int> v = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> vs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        for (int j = 0; j < v.size(); j++){
            q.push(is(v[j],vs[j]));
        }
        int sidx = 0;
        int ans = 0;
        while (sidx < s.size()){
            string curr = q.front().second;
            if (s.substr(sidx, curr.size())==curr){
                ans += q.front().first;
                sidx += curr.size();
            }
            else{
                q.pop();
            }
        }
        return ans;
    }
};