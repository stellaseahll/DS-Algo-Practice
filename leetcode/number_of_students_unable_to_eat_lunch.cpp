class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int numZeros = 0;
        int numOnes = 0;
        for (int j = 0; j < students.size(); j++){
            if (students[j] == 0){
                numZeros++;
            }
            else{
                numOnes++;
            }
        }
        for (int j = 0; j < sandwiches.size(); j++){
            if ((sandwiches[j] == 0 && numZeros == 0)|| (sandwiches[j] == 1 && numOnes == 0)) {return students.size()-j;}
            if (sandwiches[j] == 0){numZeros--;}
            else{numOnes--;}
        }
        return students.size()-sandwiches.size();
    }
};