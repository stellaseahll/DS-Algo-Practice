#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

vector<vector<int>> getAdjacencyList(const vector<string> grid){
    int n = grid.size();
    vector<vector<int>> adjList;
    for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
            if (grid[j][k]=='X'){
                vector<int> v;
                adjList.push_back(v);
                continue;
            }
            vector<int> currNeighbor;
            for (int m=j-1; m>=0; m--){
                if (grid[m][k]=='X'){
                    break;
                }
                currNeighbor.push_back(m*n+k);
            }
            for (int m=j+1; m<n; m++){
                if (grid[m][k]=='X'){
                    break;
                }
                currNeighbor.push_back(m*n+k);
            }
            for (int m=k-1; m>=0; m--){
                if (grid[j][m]=='X'){
                    break;
                }
                currNeighbor.push_back(j*n+m);
            }
            for (int m=k+1; m<n; m++){
                if (grid[j][m]=='X'){
                    break;
                }
                currNeighbor.push_back(j*n+m);
            }
            adjList.push_back(currNeighbor);
        }
    }
    return adjList;
}

void printAdjList(const vector<vector<int>> &adjList){
    for (int j = 0; j < adjList.size(); j++){
        for (int k = 0; k < adjList[j].size(); k++){
            cout << adjList[j][k] << " " ;
        }
        cout << endl;
    }
}

int bfs(const vector<vector<int>> &adjList, int startVertex, int goalVertex){
    queue<pair<int,int>> q;
    int n = adjList.size();
    vector<int> height(n,0);
    bool isVisited[n];
    memset(isVisited,false,sizeof(isVisited));
    isVisited[startVertex] = true;
    q.push(pair<int,int>(startVertex,0));
    bool isBreak = false;
    while (!q.empty() && !isBreak){
        int currVertex = q.front().first;
        int currHeight = q.front().second;
        q.pop();
        vector<int> currNeighbors = adjList[currVertex];
        for (int j = 0; j < currNeighbors.size(); j++){
            int neighbor = currNeighbors[j];
            if (neighbor == goalVertex){
                return currHeight + 1;
            }
            if (!isVisited[neighbor]){
                isVisited[neighbor] = true;
                height[neighbor] = currHeight + 1;
                q.push(pair<int,int>(neighbor,currHeight+1));
            }
        }
    }
    return -1;
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size();
    vector<vector<int>> adjList = getAdjacencyList(grid);
    // printAdjList(adjList);
    int startVertex = startX*n + startY;
    int goalVertex = goalX*n + goalY;
    // return -1;
    return bfs(adjList, startVertex, goalVertex);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

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
