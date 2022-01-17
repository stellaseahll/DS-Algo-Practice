#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */
vector<int> primes(int n){
    vector<bool> isPrime(n+1,true);
    vector<int> answer;
    isPrime[0] = false;
    isPrime[1] = false;
    for (int j = 2 ; j < n; j++){
        if (isPrime[j]){
            answer.push_back(j);
        }
        for (int k = j+j; k < n; k+=j){
            isPrime[k] = false;
        }
    }
    return answer;
}
int primeCount(long n) {
    if (n<=1){return 0;}
    vector<int> primeNumbers = primes(1000);
    int count = 0;
    long long curr = 1;
    for (int j = 0; j < primeNumbers.size() && (curr < n); j++){
        curr *= primeNumbers[j];
        if (curr < 0){break;}
        if (curr <= n){count++;}
        if (j == 15){cout << curr << endl;}
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        int result = primeCount(n);

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
