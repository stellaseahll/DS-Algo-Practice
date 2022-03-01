class Solution {
public:
    int partner(int pax){
        if (pax%2 == 0){return pax+1;}
        else{ return pax -1;}
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int ht[n];
        for (int j = 0; j < n; j++){
            int pax = row[j];
            ht[pax] = j;
        }
        int numSwap = 0;
        vector<bool> hasSwapped(n/2,false);
        for (int j = 0; j < n/2; j++){
            if (hasSwapped[j]){continue;}
            int pax1 = row[2*j];
            int pax2 = row[2*j+1];
            if (partner(pax1) == pax2){
                hasSwapped[j] = true;
                continue;
            }
            int partner1 = partner(pax1); 
            int partner2 = partner(pax2);
            int pos1 = ht[partner1];
            int pp;
            if (pos1%2 == 0){
                pp = row[pos1+1];
            }
            else{
                pp = row[pos1-1];
            }
            if (pp == partner2){
                hasSwapped[pos1/2] = true;
            }
            else{
                ht[pax2] = pos1; 
                ht[partner1] = 2*j+1;
                row[2*j+1] = partner1;
                row[pos1] = pax2;
            }
            numSwap++;
            
        }

        return numSwap;
    }
};