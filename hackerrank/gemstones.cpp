#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */

int gemstones(vector<string> arr) {
    set<string> s;
    for (int j = 0; j < arr.size(); j++){
        s.insert(arr[j]);
    }
    set<string>::iterator it;
    vector<vector<bool>> count(s.size(),vector<bool>(26,false));
    int idx = 0;
    for (it = s.begin(); it != s.end(); it++){
        string curr = *it;
        for (int j = 0; j < curr.size(); j++){
            count[idx][curr[j]-'a'] = true;
        }
        idx++;
    }
    int totalGem = 0;
    for (int j = 0; j < 26; j++){
        bool isGem = true;
        for (int k = 0; k < count.size(); k++){
            if (count[k][j] == false) {
                isGem = false;
                break;
            }
        }
        if (isGem) {totalGem++;}
    }
    return totalGem;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

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
