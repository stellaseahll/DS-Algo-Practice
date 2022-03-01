class Solution {
public:
    int maxConsecutive(string answerKey, int k, char c){
        int n = answerKey.size();
        vector<int> zeros;
        vector<int> left0(n,0);
        vector<int> right0(n,0);
        int count0 = 0;
        for (int j = 0; j < n; j++){
            if (answerKey[j] != c){
                count0++;
            }
            else{
                left0[j] = count0;
                
                if (!zeros.empty()){
                    int prevIdx = zeros.back();
                    right0[prevIdx] = count0;
                }
                zeros.push_back(j);
                count0 = 0;
            }
        }
        if (zeros.size()==0){return answerKey.size();}
        right0[zeros.back()] = count0;
        int maxSum = 0;
        
        int currSum = left0[zeros[0]];
        for (int j = 0; j < zeros.size(); j++){
            int idx = zeros[j];
            if (j < k){
                
                currSum += 1 + right0[idx];
            }
            else{
                int frontIdx = zeros[j-k];
                currSum += right0[idx] - left0[frontIdx];
            }
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int T = maxConsecutive(answerKey, k, 'T');
        int F = maxConsecutive(answerKey, k, 'F');
        // cout << T << " " << F << endl;
        return max(T,F);
    }
};