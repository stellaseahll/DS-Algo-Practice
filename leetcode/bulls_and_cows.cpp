class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0; 
        int y = 0;
        int n = secret.size();
        int htS[10], htG[10];
        memset(htG,0,sizeof(htG));
        memset(htS,0,sizeof(htS));
        for (int j = 0; j < n; j++){
            if (secret[j] == guess[j]){
                x++;
            }
            else{
                htS[secret[j]-'0']++;
                htG[guess[j]-'0']++;
            }
        }
        for (int j = 0; j < 10; j++){
            if (htS[j] >= htG[j]){
                y += htG[j];
            }
            else{
                y += htS[j];
            }
        }
        stringstream ss;
        ss << x << 'A' << y << 'B';
        return ss.str();
    }
};