#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector<int> primes(int n){
    vector<int> answer(n+1,1);
    vector<int> prime;
    answer[1] = 0;
    for (int j=2; j<n+1; j++){
        int currIdx = j+j;
        while (currIdx<n+1){
            answer[currIdx] = 0;
            currIdx+=j;
        }
    }
    for (int j = 2; j<n+1; j++){
        if (answer[j] == 1){
            prime.push_back(j);
        }
    }
    return prime;
    
}
vector<int> waiter(vector<int> number, int q) {
    stack<int> s[2];
    for (int j = number.size()-1; j>=0; j--){
        s[0].push(number[j]);
    }
    vector<int> prime = primes(q*10), answer;
    // prime.erase(prime.begin()+q,prime.end());
    
    for (int j = 0; j<q; j++){
        while (!s[j%2].empty()){
            int tp = s[j%2].top();
            if ((tp%prime[j]) == 0){
                answer.push_back(tp);
                s[j%2].pop();
            }
            else{
                s[(j+1)%2].push(tp);
                s[j%2].pop();
            }   
        }
    }
    stack<int> tmp;
    while (!s[q%2].empty()){
        tmp.push(s[q%2].top());
        s[q%2].pop();
    }
    while (!tmp.empty()){
        answer.push_back(tmp.top());
        tmp.pop();
    }
    
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
