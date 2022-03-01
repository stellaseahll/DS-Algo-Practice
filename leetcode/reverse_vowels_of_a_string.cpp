class Solution {
public:
    bool isVowel(char c){
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        deque<int> q;
        for (int j = 0; j < s.size(); j++){
            if (isVowel(s[j])){
                q.push_back(j);
            }
        }
        while (q.size()>1){
            char tmp = s[q.front()];
            s[q.front()] = s[q.back()];
            s[q.back()] = tmp;
            q.pop_front(); 
            q.pop_back();
        }
        return s;
    }
};