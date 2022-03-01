class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<vector<int>> adjList;
        map<string, int> m;
        map<int,string> mInt;
        int n = 0;
        for (int j = 0; j < recipes.size(); j++){
            string food = recipes[j];
            if (m.count(food) == 0){
                mInt[n] = food;
                m[food] = n++;
                adjList.push_back(vector<int>{});
            }
            for (int k = 0; k < ingredients[j].size(); k++){
                string ingredient = ingredients[j][k];
                if (m.count(ingredient) == 0){
                    
                    mInt[n] = ingredient;
                    m[ingredient] = n++;
                    adjList.push_back(vector<int>{});
                }
                int dest = m[food];
                int src = m[ingredient];
                adjList[src].push_back(dest);
            }
        }
        vector<int> inDegree(n,0);
        for (int j = 0; j < n; j++){
            for (int k = 0; k < adjList[j].size(); k++){
                int v = adjList[j][k];
                inDegree[v]++;
            }
        }
        queue<int> q;
        
        vector<bool> isVisited(n,false);
        for (int j = 0; j < supplies.size(); j++){
            if (m.count(supplies[j])){
                int v = m[supplies[j]];
                q.push(v);
                isVisited[v] = true;
            }
        }
        vector<string> allFood;
        while (!q.empty()){
            int curr = q.front();
            
            q.pop();
            vector<int> neighbors = adjList[curr];
            for (int j = 0; j < neighbors.size(); j++){
                
                int neighbor = neighbors[j];
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0 && !isVisited[neighbor]){
                    isVisited[neighbor] = true;
                    allFood.push_back(mInt[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        return allFood;
        
    }
};