#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
void printArr(vector<int> arr){
    for (int j = 0; j < arr.size(); j++){
        cout<< arr[j] <<" ";
    }
    cout << endl;
}
int absolute(int x){
    return (x>0)? x : -x;
}
bool isAlternate(vector<int> v1, vector<int> v2){
    if (absolute(v1.size()-v2.size())>=2){return false;}
    if (v1.size() < v2.size()){
        vector<int> tmp;
        tmp = v1;
        v1 = v2;
        v2 = tmp;
    }
    vector<int> check;
    for (int j = 0; j < v2.size(); j++){
        check.push_back(v1[j]);
        check.push_back(v2[j]);
    }
    if (v1.size() > v2.size()){
        check.push_back(v1[v1.size()-1]);
    }
    if (check.size() == 2){return true;}
    for (int j = 1; j < check.size(); j++){
        if (check[j]-check[j-1]<0) {return false;}
    }
    return true;
}
int alternate(string s) {
    vector<int> freq[26];
    memset(freq, 0, sizeof(freq));
    for (int j = 0; j < s.length(); j++){
        freq[s[j]-'a'].push_back(j);
    }
    int sum = 0;
    for (int j = 0 ; j < 26; j++){
        for (int k = 0; k < 26; k++){
            if (j==k){continue;}
            if (freq[j].size() == 0 || freq[k].size() == 0){continue;}
            if (isAlternate(freq[j], freq[k])){
                int tmp = freq[j].size()+freq[k].size();
                if (tmp > sum){
                    sum = tmp;
                }
            }
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

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
