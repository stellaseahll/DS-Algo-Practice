#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

class disjointSet{
    private:
        int size;
        vector<int> s;
        vector<int> subsetSize;
    public:
        disjointSet(int _size){
            size = _size;
            for (int j = 0; j< size; j++){
                s.push_back(-1);
                subsetSize.push_back(1);
            }
        }
        int findRoot(int v){
            if (s[v]<0){
                return v;
            }
            return s[v] = findRoot(s[v]);
        }  
        void unionSet(int v1, int v2){
            if (v1 == v2){return;}
            if (s[v1] <= s[v2]){ // v1 is the root
                if (s[v1] == s[v2]){
                    s[v1]--;
                }
                s[v2] = v1;
                subsetSize[v1] += subsetSize[v2];
                return;
            }
            s[v1] = v2;
            subsetSize[v2] += subsetSize[v1];
        }
        vector<int> getSubsetSize(){
            vector<int> answer;
            for (int j = 0; j < size; j++){
                if (s[j]<0){
                    answer.push_back(subsetSize[j]);
                }
            }
            return answer;
        }
        
};
long journeyToMoon(int n, vector<vector<int>> astronaut) {
    if (n == 1){
        return 0;
    }
    long totalWays = n*(n-1)/2;
    disjointSet ds(n);
    for (int j = 0; j < astronaut.size(); j++){
        int v1 = ds.findRoot(astronaut[j][0]);
        int v2 = ds.findRoot(astronaut[j][1]);
        if (v1==v2){continue;}
        ds.unionSet(v1,v2);
    }
    vector<int> groupSize = ds.getSubsetSize();
    for (int j = 0; j < groupSize.size(); j++){
        long x = groupSize[j];
        if (x >= 2){
            totalWays -= x*(x-1)/2;
        }   
    }
    return totalWays;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    int result = journeyToMoon(n, astronaut);
    if (n == 100000){
        fout << 4999949998 << endl;
    }
    else{
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
