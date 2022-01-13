#include <iostream>
#include <vector>
using namespace std;

int maximumCost(int money, vector<vector<int>> garment){
    int numGarment = garment.size();
    int dp[numGarment+1][money+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int j = 1; j <= numGarment; j++){
        vector<int> currGarment = garment[j-1];
        for (int k = 0; k < currGarment.size(); k++){
            for (int m = 0; m < money+1; m++){
                int currCost = currGarment[k];
                if (dp[j-1][m]==1){
                    if (m+currCost < money+1){
                        dp[j][m+currCost] = 1;
                    }
                }
            }
        }
    }
    int answer = -1;
    for (int m = money; m >= 0; m--){
        if (dp[numGarment][m] > 0){
            return m;
        }
    }
    return answer;
}
int main(){
    int numCase;
    cin >> numCase;
    for (int j = 0; j < numCase; j++){
        int money, numGarment;
        vector<vector<int>> garment;
        cin >> money >> numGarment;
        for (int k = 0; k < numGarment; k++){
            int n;
            cin >> n;
            vector<int> tmpGarment;
            for (int m = 0; m < n; m++){
                int cost; 
                cin >> cost;
                tmpGarment.push_back(cost);
            }
            garment.push_back(tmpGarment);
        }
        int answer =  maximumCost(money, garment);
        if (answer == -1){
            cout << "no solution" << endl;
        }
        else{
            cout<< answer << endl;
        }

    }
}