#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    int freqTable[26];
    for (int j = 0; j < s.length(); j++){
        if (s[j]<=90 && s[j]>=65){
            freqTable[s[j]-65]++;
        }
        else if (s[j]<=122 && s[j]>=97){
            freqTable[s[j]-97]++;
        }
    }
    for (int j=0; j<26; j++){
        if (freqTable[j] == 0){
            return "not pangram";
        }
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
