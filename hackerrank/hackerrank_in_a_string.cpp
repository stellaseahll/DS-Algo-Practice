#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'hackerrankInString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string hackerrankInString(string s) {
    string t = "hackerrank";
    int count[t.length()];
    memset(count, 0 , sizeof(count));
    int sidx = 0;
    for (int j = 0; j < t.length(); j++){
        while (sidx < s.length() && s[sidx] != t[j]){
            sidx++;
        }
        if (s[sidx] == t[j]){
            count[j]++;
        }
        if (s[sidx] == 'r'){
            sidx++;
        }
    }
    for (int k = 0 ; k < t.length(); k++){
        if (count[k]==0){return "NO";}
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

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
