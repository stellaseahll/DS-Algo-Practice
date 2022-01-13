#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int maximumCost(vector<int> itemCost, vector<int> itemWeight, vector<int> family){
    int dp[31];
    int max[31];
    memset(dp,0,sizeof(dp));
    for (int j = 0; j < itemCost.size(); j++){
        int currCost = itemCost[j];
        int currWeight = itemWeight[j];
        for (int w = 30; w >= currWeight; w--){
            if (dp[w] < (dp[w-currWeight]+currCost)){
                dp[w] = dp[w-currWeight]+currCost;
            }
        }
    }
    int answer = 0;
    for (int j = 0; j < family.size(); j++){
        answer += dp[family[j]];
    }
    return answer;
}
int main(){
    int numCase;
    cin >> numCase;
    for (int j = 0; j < numCase; j++){
        int numItem, numFamily;
        cin >> numItem;
        vector<int> itemCost(numItem,0), itemWeight(numItem,0);
        for (int k = 0; k < numItem; k++){
            cin >> itemCost[k] >> itemWeight[k];
        }
        cin >> numFamily;
        vector<int> family(numFamily,0);
        for (int k = 0; k < numFamily; k++){
            cin >> family[k];
        }
        cout << maximumCost(itemCost, itemWeight, family) << endl;

    }
}