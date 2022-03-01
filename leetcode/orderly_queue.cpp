class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1){
            sort(s.begin(),s.end());
            return s;
        }
        char smallest = 'z'+1;
        for (int j = 0; j < s.size(); j++){
            if (s[j] < smallest){
                smallest = s[j];
            }
        }
        vector<string> possible;
        for (int j = 0; j < s.size(); j++){
            if (s[j] == smallest){
                int l = s.size()-j;
                string str = s.substr(j,l) + s.substr(0,s.size()-l);
                possible.push_back(str);
            }
        }
        sort(possible.begin(), possible.end());
        return possible[0];
    }
}; 

