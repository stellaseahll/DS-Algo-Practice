class DisjointSet{
    private:
    int size;
    vector<int> s;
    
    public:
    DisjointSet(int _size){
        size = _size;
        s = vector<int>(size,-1);
    }
    bool insert(int v1, int v2){
        int p1 = find(v1);
        int p2 = find(v2);
        if (p1 == p2){return false;}
        if (s[p1] < s[p2]){ //p1 is parent
            s[p2] = p1;
            return true;
        }
        if (s[p1] == s[p2]){ // p2 is parent
            s[p2]--;
        }
        s[p1] = p2;
        return true;
    }
    
    int find(int v){
        if (s[v]<0){return v;}
        return s[v] = find(s[v]);
    }
};

class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for (int j = 0; j < n; j++){
            int x = edges[j][0]-1;
            int y = edges[j][1]-1;
            if (!ds.insert(x,y)){return edges[j];}
        }
        return {};
    }
};