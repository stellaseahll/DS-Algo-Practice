#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    stringstream ss; 
    ss << s.substr(0,2);
    int hour;
    ss >> hour;
    if (s[8] == 'A'){
        if (hour == 12){
            return "00" + s.substr(2,6);
        }
        else{
            return s.substr(0,8);
        }
    }
    if (hour == 12){
        return s.substr(0,8);
    }
    stringstream ss2;
    ss2 << 12+hour;
    string hours;
    ss2 >> hours;
    return hours + s.substr(2,6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
