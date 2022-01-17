#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    int count = 0;
    for (int j = 0; j < s.length(); j++){
        if (j%3==0 || j%3 == 2){
            if (s[j] != 'S'){count++;}
        }
        else{
            if (s[j] != 'O'){count++;}
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
