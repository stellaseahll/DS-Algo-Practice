#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> fullGrid(int row, int col){
    vector<string> full;
    string s = "";
    for (int k=0; k<col; k++){
        s+= 'O';
    }
    for (int j=0; j<row; j++){
        full.push_back(s);
    }
    return full;
}

// bool compareGrids(const vector<string> grid1, const vector<string> grid2){
//     for (int j = 0; j<grid1.size(); j++){
//         for (int k = 0; k<grid2[0].length(); k++){
//             if (grid1[j][k]!=grid2[j][k]){
//                 return false;
//             }    
//     }
//     return true;
// }

void printGrid(int numRow, int numCol,vector<string>  grid){
    for (int j = 0; j<numRow; j++){
        cout << grid[j] << endl;
    }
    cout << endl << endl;
}
void bomb(int j, int k, int numRow, int numCol, vector<string> &grid){
    // if ((j==0 || j == numRow-1) && (k==0 || k==numCol-1)){
    //     grid[j][k] = '.';
    //     return;
    // }
    for (int row = j-1; row <= j+1; row++){
        if (row<0 || row >=numRow){
            continue;
        }
        grid[row][k] = '.';
    }
    for (int col = k-1; col <= k+1; col++){
        if (col<0 || col >=numCol){
            continue;
        }
        grid[j][col] = '.';
    }
    return;
}
vector<string> bomberMan(int n, vector<string> grid){
    int currN;
    int numRow = grid.size();
    int numCol = grid[0].length();
    map<string,int> m;
    if (n==1) {
        return grid;
    }
    if (n%2 == 0) {
        return fullGrid(numRow, numCol);
    }
    vector<string> tmpGrid, currGrid, full;
    full = fullGrid(numRow, numCol);
    currGrid = grid;
    currN = 3;
    string s;
    while (currN <= n){
        tmpGrid = full;
        for (int j = 0; j<numRow; j++){
            for (int k = 0; k<numCol; k++) {
                if (currGrid[j][k] == 'O'){
                    bomb(j,k,numRow,numCol,tmpGrid);
                }
            }
        }
        currGrid = tmpGrid;
        s = "";
        for (int j = 0; j <numRow; j++){
            s+= currGrid[j];
        }
        if (m.count(s)!=0){
            break;
        }
        m[s] = currN;
        currN += 2;
    }
    if (currN-2 == n){
        return currGrid;
    }
    map<string,int>::iterator it;
    string answer;
    vector<string> vs;
    for (it = m.begin(); it != m.end(); it++){
        // cout << n << currN << m[s] << endl;
        if (it->second == (m[s]+(n-m[s])%(currN-m[s]))){
            answer = it->first;
        }
    }
    for (int j = 0; j<numRow; j++){
        // cout << answer.substr(numCol*j,numCol) << " " ;
        vs.push_back(answer.substr(numCol*j,numCol));
    }
    return vs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
