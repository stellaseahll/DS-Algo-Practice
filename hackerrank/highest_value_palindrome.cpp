#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {
    int maxReplacement = 0;
    if (k > n){
        string tmp(n,'9');
        return tmp;
    }
    for (int j = 0; j < s.length()/2; j++){
        if (s[j] != s[s.length()-1-j]){
            maxReplacement++;
            if (maxReplacement > k){
                return "-1";
            }
        }
    }
    char tmp[s.length()];
    for (int j = 0; j <= s.length()/2; j++){
        if (s[j] >= s[s.length()-1-j]){
            tmp[j] = s[j];
            tmp[s.length()-1-j] = s[j];
        }
        else{
            tmp[j] = s[s.length()-1-j];
            tmp[s.length()-1-j] = s[s.length()-1-j];
        }
    }
    int start = 0, end = s.length()-1;
    k = k-maxReplacement;
    while (k>0 && start<end){
        if (tmp[start] != '9'){
            if (s[start]!='9' && s[end]!='9' && s[start]!=s[end]){
                k +=1;
            }
            if (k-2<0){break;}
            tmp[start] = '9';
            tmp[end] = '9';
            k-=2;
        }
        start++;
        end--;
    }
    if (k==1){
        tmp[n/2] = '9';
    }
    string answer = tmp;
    return answer.substr(0,n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

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
