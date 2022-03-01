typedef pair<int,int> ii;
class Solution {
public:
    int max(int a, int b){
        if (a>b){return a;}
        return b;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        ii bestPair(values[0],0);
        int currMax = 0;
        for (int j = 1; j < values.size(); j++){
            currMax = max(currMax, bestPair.first+values[j]-j+bestPair.second);
            if (bestPair.first-values[j] < j-bestPair.second){
                bestPair = ii(values[j],j);
            }
        }
        return currMax;
    }
};