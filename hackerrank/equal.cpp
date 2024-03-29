#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int min(int a, int b, int c){
    if (a<=b && a<=c){return 1;}
    if (b<=c){return 2;}
    return 5;
}
int equal(vector<int> arr) {
    int memo[1002];
    memset(memo,0,sizeof(memo));
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 2;
    memo[4] = 2;
    memo[5] = 1;
    int jump[3] = {1,2,5};
    for (int j = 6; j < 1002; j++){
        int jumpLength = min(memo[j-1],memo[j-2],memo[j-5]); 
        memo[j] = memo[j-jumpLength] + 1;
    }
    vector<int> freqTable(1002,0);
    for (int j = 0; j < arr.size(); j++){
        freqTable[arr[j]]++;
    }
    vector<int> noDuplicate;
    for (int j = 0; j < 1002; j++){
        if (freqTable[j] > 0){
            noDuplicate.push_back(j);
        }
    }
    sort(noDuplicate.begin(),noDuplicate.end());
    deque<int> dq; 
    for (int j = 0; j < noDuplicate.size(); j++){
        for (int k = 0; k < freqTable[noDuplicate[j]]; k++){
            dq.push_front(noDuplicate[j]);
        }
    }
    int count = 0;
    while (dq.front()!=dq.back()){
        int diff = dq.front()-dq.back(); 
        count += memo[diff];
        dq.pop_front();
        dq.push_back(dq.back()); 
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = equal(arr);

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
