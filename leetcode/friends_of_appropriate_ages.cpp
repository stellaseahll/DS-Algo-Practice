class Solution {
public:
    int getRequests(const vector<int>& ages, int age){
        int lower = age/2 + 7;
        int upper = age;
        if (lower >= age) {
            return 1;
        }
        if (age == ages[0]){

            return upper_bound(ages.begin(), ages.end(),upper)-ages.begin();
        }
        int idxLow = upper_bound(ages.begin(), ages.end(),lower)-ages.begin();
        int idxUp = upper_bound(ages.begin(), ages.end(),upper)-ages.begin();
        return idxUp-idxLow;
        
    }
    int numFriendRequests(vector<int>& ages) {
        int numRequest = 0;
        sort(ages.begin(),ages.end());
        for (int j = 0; j < ages.size(); j++){
            // cout << getRequests(ages,ages[j])-1 << endl;
            numRequest += getRequests(ages,ages[j])-1;
        }
        return numRequest;
    }
};