class Solution {
public:
    int abs(int x){
        if (x>0){return x;}
        return -x;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> answer;
        for (int j = 0; j < asteroids.size(); j++){
            if (answer.empty() || !(answer.back() > 0 && asteroids[j] < 0) ){
                answer.push_back(asteroids[j]);
                continue;
            }

            while (!answer.empty() && answer.back() > 0 && abs(asteroids[j]) > abs(answer.back())){
                answer.pop_back();
            }
            if (answer.empty() || answer.back() < 0){
                answer.push_back(asteroids[j]);
            }
            else if (asteroids[j] == -answer.back()){
                answer.pop_back();
            }
            
        }
        return answer;
    }
};