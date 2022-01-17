#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

int legoBlocks(int n, int m) {
    // if (n == 1) {return 0;}
    long long X = 1000000007;
    long long a[m+1];
    memset(a,0,sizeof(a));
    a[0] = 1;
    for (int j = 1; j < m+1; j++){
        for (int k = j-1; k >= j-4 && k >=0 ; k--){
            a[j]+=a[k];
        }
        a[j] = a[j]%X;
    }
    for (int j = 1; j < m+1; j++){
        long long tmp = a[j];
        for (int k = 1; k < n; k++){
            a[j] *= tmp;
            a[j] = a[j]%X;  
        }
        a[j] = a[j]%X;
    }

    long long r[m+1];
    memset(r,0,sizeof(r));
    r[1] = 1;
    for (int j = 2; j < m+1; j++){
        r[j] = a[j]; //total ways
        for (int k = 1; k < j; k++){
            r[j] -= r[k]*a[j-k];
            r[j] = r[j] % X;
        }
        r[j] = r[j] % X;
    }
    cout << r[m] << " " << r[m]%X;
    // return (int) (r[m] % X);
    if (r[m] >=0) {return (int) r[m]%X;}
    return (int) (r[m]+X);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

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
