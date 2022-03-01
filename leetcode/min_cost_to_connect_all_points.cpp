struct Edge {
    int p1; 
    int p2;
    int weight;
    Edge() {}
    Edge(int a, int b, int w){
        p1 = a;
        p2 = b;
        weight = w;
    }
    bool operator() (const Edge& lhs, const Edge& rhs){
        return (lhs.weight>rhs.weight);
    }
};

class DisjointSet{
    private:
    int size; 
    vector<int> s;
    vector<int> pSize;
    int maxSize;
    public:
    DisjointSet(int _size){
        size = _size;
        s = vector<int>(size,-1);
        pSize = vector<int>(size,1);
        maxSize = 1;
    }
    int join(int v1, int v2){
        if (v1 == v2){return -1;}
        if (s[v1] < s[v2]){ // v1 is parent
            s[v2] = v1;
            pSize[v1] += pSize[v2];
            if (pSize[v1] > maxSize){maxSize = pSize[v1];}
            return maxSize;
        }
        if (s[v1] == s[v2]){ // v2 parent now
            s[v2]--;
        }
        s[v1] = v2;
        pSize[v2] += pSize[v1];
        if (pSize[v2] > maxSize){maxSize = pSize[v2];}
        return maxSize;
    }
    
    int find(int v){
        if (s[v] < 0){return v;}
        return s[v] = find(s[v]);
    }
};


class Solution {
public:
    vector<Edge> getEdgeList(const vector<vector<int>>& points){
        int n = points.size();
        vector<Edge> edges;
        for (int j = 0; j < n; j++){
            for (int k = j+1; k < n; k++){
                int dist = abs(points[j][0]-points[k][0])+abs(points[j][1]-points[k][1]);
                Edge e(j,k,dist);
                // e.p1 = j;
                // e.p2 = k;
                // e.weight = dist;
                edges.push_back(e);
            }
        }
        return edges;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edges = getEdgeList(points);
        int nE = edges.size();
        int nP = points.size();
        priority_queue <Edge,vector<Edge>,Edge> pq;
        
        // Initialize
        for (int j = 0; j < edges.size(); j++){
            pq.push(edges[j]);
        }
        DisjointSet ds(nP);
        int size = 0;
        int cost = 0;
        while (!pq.empty() && size < nP){
            Edge e = pq.top(); 
            pq.pop();
            
            int v1 = ds.find(e.p1);
            int v2 = ds.find(e.p2);
            if (v1 != v2){
                size = ds.join(v1,v2);
                cost += e.weight;
            }
        }
        return cost;
        
    }
};