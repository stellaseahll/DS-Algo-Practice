#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */
 class disjointSet{
    private: 
        int size;
        vector<int> s;
    public:
        disjointSet(int _size){
            size = _size;
            for (int i = 0; i<size; i++){
               s.push_back(-1); // initialize all to -1;
            }
        }
        void unionSet(int root1, int root2){
            if (root1 == root2){ // the two rootes are the same
                return;
            }
            if (s[root2] < s[root1]) {// root 2 is deeper than root 1
                s[root1] = root2; // change the parent of root1 to root2
                return;
            }
            if (s[root1] == s[root2]){// same height currently
                s[root1]--; // increase the depth of 1
            }
            s[root2] = root1; // change the parent of root2 to root1
            return;
        }

        void printSet(){
            for (int i = 0; i<size; i++){
                cout << i << ": " << s[i] << endl;
            }
        }

        int find(int x){
            if (s[x] < 0){
                return x;
            }
            return s[x] = find(s[x]);
        }
        long getNumParents(){
            long count = 0;
            for (int j = 0; j < size; j++){
                if (s[j]<0){
                    count++;
                }
            }
            return count;
        }
};
// class disjointSet{
//     private:
//         int size;
//         vector<long> setSize;
//         vector<int> set;
//     public:
//         disjointSet(int _size){
//             size = _size;
//             for (int j = 0; j < size; j++){
//                 set.push_back(-1); // initial height = 0;
//                 setSize.push_back(1);
//             } 
//         }
//         int root(int v){
//             if (set[v]<0){
//                 return v;
//             }
//             return set[v] = root(set[v]);
//         }
//         // int root(int v){
//         //     int curr = v;
//         //     while (set[curr]>=0){
//         //         curr = set[curr];
//         //     }
//         //     return curr;
//         // }
//         void unionSet(int v1, int v2){
//             v1 = root(v1);
//             v2 = root(v2);
//             if (v1 == v2){ // same root
//                 return; 
//             }
//             if (set[v1] < set[v2]){ // v1 is deeper than v2, v1 is parent
//                 set[v2] = v1;
//                 return;
//             }
//             if (set[v1] == set[v2]){ // v1 and v2 same height, we make v2 parent            
//                 set[v2]--;
//             }
//             set[v1] = v2;
//             return;
//         }
//         vector<int> getParents(){
//             vector<int> parents;
//             for (int j = 0; j < size; j++){
//                 if (set[j]<0){
//                     parents.push_back(j);
//                 }
//             }
//             return parents;
//         }
//         long getSubsetSize(int parent){
//             return setSize[parent];
//         }
//         void printSet(){
//             for (int j = 0; j < size; j++){
//                 cout << set[j] << " ";
//             }
//             cout << endl;
//         }
//         void printSize(){
//             for (int j = 0; j < size; j++){
//                 cout << setSize[j] << " ";
//             }
//             cout << endl;
//         }
// };

// long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
//     if (c_lib <= c_road){
//         return c_lib*n;
//     }
//     disjointSet ds(n);
//     for (int j = 0; j < cities.size(); j++){
//         int r1 = ds.find(cities[j][0]-1);
//         int r2 = ds.find(cities[j][1]-1);
//         if (r1 == r2){continue;}
//         ds.unionSet(r1,r2);
//     }
//     long ps = ds.getNumParents();
//     long nc = n;
//     long cost = ps*c_lib + (nc-ps)*c_road;
//     return cost;
// }
void printAdjList(const vector<vector<int>> &adjList){
    for (int j = 0; j < adjList.size(); j++){
        for (int k = 0; k < adjList[j].size(); k++){
            cout << adjList[j][k] << " ";
        }
        cout << endl;
    }
}

void printArr(const vector<bool> &v){
    for (int j = 0; j<v.size(); j++){
        cout << v[j] << " ";
    }
    cout << endl;
}

void bfs(const vector<vector<int>> &adjList, int root, vector<bool> &isVisited){
    queue<int> q;
    q.push(root);
    isVisited[root] = true;
    while (!q.empty()){
        int curr = q.front();
        q.pop();
        vector<int> neighbors = adjList[curr];
        for (int j = 0; j < neighbors.size(); j++){
            int neighbor = neighbors[j];
            if (!isVisited[neighbor]){
                isVisited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if (c_lib <= c_road){
        long cl = c_lib;
        return cl*n;
    }
    vector<vector<int>> adjList;
    for (int j = 0; j < n ; j++){
        vector<int> t;
        adjList.push_back(t);
    }

    for (int j = 0; j < cities.size(); j++){
        int r1 = cities[j][0]-1;
        int r2 = cities[j][1]-1;
        if (r1 == r2){
            continue;
        }
        adjList[r1].push_back(r2);
        adjList[r2].push_back(r1);
    }
    vector<bool> isVisited(n,false);
    long count = 0;
    for (int j = 0; j < n; j++){
        if (!isVisited[j]){
            count++;
            bfs(adjList,j,isVisited);
        } 
    } 
    long nc = n;
    long cost = count*c_lib + (nc-count)*c_road;
    return cost;

}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
