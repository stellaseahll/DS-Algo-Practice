
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int checkPalindrome(string s){
    for (int j = 0; j < s.length()/2 ; j++){
        if (s[j] != s[s.length()-1-j]){
            return j;
        }
    }
    return -1;
}

int palindromeIndex(string s) {
    int idx = checkPalindrome(s);
    if (idx == -1) {return -1;}
    int leftIdx = idx, rightIdx = s.length()-1-idx;
    if (checkPalindrome(s.substr(leftIdx,rightIdx-leftIdx))==-1){return rightIdx;}
    if (checkPalindrome(s.substr(leftIdx+1,rightIdx-leftIdx))==-1){return leftIdx;}
    return -1;
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

        int result = palindromeIndex(s);

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
