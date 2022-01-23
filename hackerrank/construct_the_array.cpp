#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countArray' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER x
 */
// long ways(int currPosition, int currNumber, const int n, const int k, const int x, vector<vector<long>>& memo){
//     if (currPosition == n-1 && currNumber == x){return 1;}
//     if (currPosition == n-1 && currNumber != x){return 0;}
//     if (currNumber == k+1){return 0;}
//     if (memo[currNumber][currPosition]!=-1){return memo[currNumber][currPosition];}
//     if (currPosition == 0){
//         for (int j = 2; j <=k; j++){
//             memo[1][currPosition] += ways(1,j,n,k,x,memo);
//         }
//         return memo[1][currPosition];   
//     }
//     long numWays = 0;
//     for (int j = 1; j <= k; j++){
//         if (j == currNumber){continue;}
//         numWays += ways(currPosition+1,j,n,k,x,memo);
//     }
//     return memo[currNumber][currPosition] = numWays;  
// }

// void printArray(vector<vector<long>> memo){
//     for (int j = 0; j < memo.size(); j++){
//         for (int k = 0; k < memo[j].size(); k++){
//             cout << memo[j][k] << " ";
//         }
//         cout << endl;
//     }
//     return;
// }
long countArray(int n, int k, int x) {
    long X = 1000000007;
    vector<pair<long,long>> memo(n+1,pair<long,long>(0,0));
    int numChoice = k-1;
    memo[1].first = 0;
    memo[1].second = 1;
    for (int j = 2; j <= n; j++){
        memo[j].first = (memo[j-1].second*numChoice) % X;
        memo[j].second = memo[j-1].first % X + (memo[j-1].second*(numChoice-1))%X;
        memo[j].second = memo[j].second % X;
    }
    if (x==1) {return memo[n-1].first;}
    return memo[n-1].second;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    int x = stoi(first_multiple_input[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

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
