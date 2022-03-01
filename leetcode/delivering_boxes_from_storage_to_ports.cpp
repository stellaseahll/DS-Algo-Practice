int INF = 1000000000;
typedef pair<int,int> ii;
class Solution {
public:
    int min(int a, int b){
        if (a<b){return a;}
        return b;
    }
    int numTrips(int start, const vector<vector<int>>& boxes, int maxBoxes, int maxWeight, vector<int>& memo){
        if (memo[start] != -1){return memo[start];}
        int minStep = INF;
        int currWeight = 0;
        int currBox = 0;
        vector<int> qsize;
        int nextPortIdx = boxes.size();
        stack<ii> stk;
        for (int j = start; j < boxes.size(); j++){
            currWeight += boxes[j][1];
            currBox++;
            if (stk.empty() || stk.top().first != boxes[j][0]){
                stk.push(ii(boxes[j][0],j));
            }
            else{
                stk.top().second = j;
            }            
            if (currWeight > maxWeight || currBox > maxBoxes){
                nextPortIdx = stk.top().second;
                stk.pop();
                break;
            }
        }
        if (nextPortIdx == boxes.size()){
            return memo[start] = stk.size() + 1;
        }
        int currPortIdx = start;
        if (!stk.empty()){
            currPortIdx = stk.top().second;
        }
        if (currPortIdx+1 == nextPortIdx){
            int x = stk.size()+1;
            if (stk.empty()){
                x++;
            }
            return memo[start] = x + numTrips(nextPortIdx,boxes,maxBoxes,maxWeight,memo);
        }
        for (int j = nextPortIdx; j > currPortIdx; j--){
            int x = stk.size()+2;
            // if (stk.empty()){
            //     x++;
            // }
            minStep = min(minStep, x +  numTrips(j,boxes,maxBoxes,maxWeight,memo));
        }
        int x = stk.size()+1;
        if (stk.empty()){
              x++;
        }
        minStep = min(minStep,x +  numTrips(currPortIdx+1,boxes,maxBoxes,maxWeight,memo));
        
//         for (int j = start; j < boxes.size(); j++){
//             currWeight += boxes[j][1];
//             currBox++;
//             if (currWeight <= maxWeight && currBox <= maxBoxes){
//                 end = j;
//                 if (qsize.empty()){
//                     qsize.push_back(2);
//                 }
//                 else if (prevPort != boxes[end][0]){
//                     qsize.push_back(qsize.back()+1);
//                 }
//                 else{
//                     qsize.push_back(qsize.back());
//                 }
//                 prevPort = boxes[end][0];
//             }
//             else{
//                 break;
//             }
//         }
        
//         for (int j = end; j >= start; j--){
//             if (j == boxes.size()-1){
//                 minStep = min(minStep, qsize[j-start]);
//             }
//             else{
//                 minStep = min(minStep, qsize[j-start] + numTrips(j+1,boxes,maxBoxes,maxWeight,memo));
//             }
//         }
        return memo[start] = minStep;
    }
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        vector<int> memo(boxes.size(),-1);
        numTrips(0, boxes, maxBoxes, maxWeight, memo);

        return memo[0];
    }
};