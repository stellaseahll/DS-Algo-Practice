#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int nUpper = 0, nLower = 0, nDigit = 0, nOthers = 0;
    for (int j = 0; j < password.length(); j++){
        if (password[j]>='0' && password[j]<='9'){
            nDigit++;
        }
        else if (password[j]>='a' && password[j]<='z'){
            nLower++;
        }
        else if (password[j]>='A' && password[j]<='Z'){
            nUpper++;
        }
        else{
            nOthers++;
        }
    }
    int numToAdd = 0;
    int diff = (6 - password.length() > 0)? 6 - password.length() : 0;
    if (nUpper == 0){numToAdd++;}
    if (nLower == 0){numToAdd++;}
    if (nDigit == 0){numToAdd++;}
    if (nOthers == 0){numToAdd++;}
    cout << numToAdd << " " << diff ;
    return (numToAdd > diff)? numToAdd : diff;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

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
