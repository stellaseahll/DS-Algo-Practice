#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
int absolute(int x){
    return (x>0)? x: -x;
}
string funnyString(string s) {
    for (int j = 1; j < s.size(); j++){
        int d1 = abs(s[j] - s[j-1]);
        int d2 = abs(s[s.size()-j]-s[s.size()-j-1]);
        if (d1 != d2){
            return "Not Funny";
        }
    }
    return "Funny";
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

        string result = funnyString(s);

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
